#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <array>
#include <stdexcept>

#include "pbkdf2.h" // Incluye a su vez hmac_sha256.h y sha256.h
#include "secure_random.h"

#include <aes.hpp>

#include "Strings.h"

// 1. Cargar todo el fichero en un std::vector<uint8_t>
inline std::vector<uint8_t> cargarFichero(const std::string& ruta) {
    // Abrimos en modo binario y posicionamos el puntero directamente al final (ate)
    std::ifstream archivo(ruta, std::ios::binary | std::ios::ate);

    if (!archivo.is_open()) {
        std::cerr << T(Str::ReadFileErrorMessage) << ": " << ruta << "\n";
        return {};
    }

    // Al estar al final, tellg() nos da el tamaño exacto del archivo en bytes
    std::streamsize tamano = archivo.tellg();
    
    // Volvemos al principio del archivo para empezar la lectura
    archivo.seekg(0, std::ios::beg);

    // Reservamos el espacio exacto en el vector
    std::vector<uint8_t> buffer(tamano);

    // Leemos todo el contenido directamente en la memoria del vector
    if (!archivo.read(reinterpret_cast<char*>(buffer.data()), tamano)) {
        std::cerr << T(Str::ErrorWhileReadingMessage) << "\n";
        return {};
    }

    return buffer;
}

// 2. Volcar el contenido de un std::vector<uint8_t> a un fichero
inline bool guardarFichero(const std::string& ruta, const std::vector<uint8_t>& datos) {
    // Abrimos el archivo en modo binario para escritura (sobrescribe si ya existe)
    std::ofstream archivo(ruta, std::ios::binary);

    if (!archivo.is_open()) {
        std::cerr << T(Str::WriteFileErrorMessage) << ": " << ruta << "\n";
        return false;
    }

    // Escribimos el bloque completo de datos desde el puntero .data()
    archivo.write(reinterpret_cast<const char*>(datos.data()), datos.size());

    return archivo.good(); // Devuelve true si la escritura fue exitosa
}

// Número de iteraciones de PBKDF2. Se guarda también en el fichero cifrado (no es secreto),
// pero este valor es el que se usa por defecto al generar un nuevo fichero.
// Ver conversación: 300000 es un punto de partida razonable dado que ya usamos
// contraseñas largas/complejas; ajustar si el tiempo de espera no conviniera.
extern uint32_t PBKDF2_ITERATIONS;

// Límite de sensatez para el número de iteraciones leído de un fichero cifrado.
// Sin este límite, un atacante con acceso de escritura al fichero podría fijar
// "iterations" a un valor absurdamente alto (ej. 4 mil millones); como el MAC
// solo puede verificarse DESPUÉS de derivar las claves (y derivarlas es lo que
// consume las iteraciones), el usuario legítimo se quedaría esperando horas o
// días antes de que decrypt() llegara siquiera a rechazar el fichero. Este límite
// se comprueba ANTES de derivar ninguna clave, cortando el ataque de raíz.
// 10 millones es un margen amplio por encima de cualquier valor razonable que
// usaríamos nosotros mismos (300000), pero sigue acotando el tiempo máximo posible.
constexpr uint32_t MAX_ALLOWED_ITERATIONS = 10000000;

// Longitud de clave para AES-256, en bytes.
constexpr size_t AES_KEY_LENGTH_BYTES = 32;

// Longitud de la sal, en bytes. 16 bytes (128 bits) es el tamaño estándar recomendado.
constexpr size_t SALT_LENGTH_BYTES = 16;

// PBKDF2 deriva 64 bytes en total: los primeros 32 para la clave de cifrado AES-256,
// los siguientes 32 para la clave de autenticación HMAC. Usar dos claves independientes
// (en vez de reutilizar la misma para cifrar y autenticar) es la práctica recomendada
// para el patrón encrypt-then-MAC.
constexpr size_t DERIVED_KEY_TOTAL_LENGTH_BYTES = 64;
constexpr size_t HMAC_KEY_LENGTH_BYTES = 32;

// Comparación en tiempo constante: evita que el tiempo de ejecución de la comparación
// filtre información sobre en qué byte difieren dos buffers (timing side-channel).
// A diferencia de std::vector::operator==, que puede terminar en cuanto encuentra
// la primera diferencia, aquí siempre se recorren todos los bytes.
inline bool constantTimeEquals(const std::vector<uint8_t>& a, const std::vector<uint8_t>& b) {
    if (a.size() != b.size()) {
        return false; // La longitud en sí no es secreta, comparar tamaños no filtra nada relevante
    }

    uint8_t diff = 0;
    for (size_t i = 0; i < a.size(); i++) {
        diff |= (a[i] ^ b[i]);
    }

    return diff == 0;
}

inline std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;

    for (char c : str) {
        if (c == delimiter) {
            tokens.push_back(token);
            token.clear();
        } else {
            token += c;
        }
    }
    tokens.push_back(token); // añade el último trozo (o el único, si no hay delimitador)

    return tokens;
}

inline std::string toHexString(const std::vector<uint8_t>& data) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    
    for(const auto& byte : data) {
        ss << std::setw(2) << static_cast<int>(byte);
    }
    
    return ss.str();
}

template <size_t N>
inline std::string toHexString(const std::array<uint8_t, N>& data) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');

    for (const auto& byte : data) {
        ss << std::setw(2) << static_cast<int>(byte);
    }

    return ss.str();
}

inline std::vector<uint8_t> fromHexString(const std::string& hexStr) {
    // Check for valid input: must have even length
    if(hexStr.length() % 2 != 0) {
        throw std::invalid_argument(T(Str::HexStringErrorMessage));
    }
    
    std::vector<uint8_t> result;
    result.reserve(hexStr.length() / 2);
    
    for(size_t i = 0; i < hexStr.length(); i += 2) {
        std::string byteString = hexStr.substr(i, 2);
        
        // Convert hex string to integer using std::stoi with base 16
        try {
            uint8_t byte = static_cast<uint8_t>(std::stoi(byteString, nullptr, 16));
            result.push_back(byte);
        } catch (const std::exception& e) {
            throw std::invalid_argument(T(Str::InvalidHexCharacterErrorMessage));
        }
    }
    
    return result;
}

// NOTA (punto 3 de la revisión): con la migración a AES-CTR, el cifrado ya no
// requiere padding (CTR convierte AES en un cifrador de flujo). Las antiguas
// funciones padData/removePadding se eliminan por completo: el bug de padding
// queda resuelto por eliminación de la causa, no parcheado.

// NOTA (punto 1 de la revisión): sustituye la antigua keyFromPassword (XOR simple,
// sin coste computacional, sin sal) por una derivación real con PBKDF2-HMAC-SHA256.
// La sal es distinta en cada llamada a encrypt() y se transporta junto al fichero
// (no es secreta, es una práctica estándar).
//
// NOTA (punto 4 de la revisión): ahora deriva 64 bytes en una sola llamada a PBKDF2
// y los reparte en dos claves independientes: [0:32) para AES-256, [32:64) para HMAC.
struct DerivedKeys {
    std::vector<uint8_t> encryptionKey; // 32 bytes, para AES-256
    std::vector<uint8_t> macKey;        // 32 bytes, para HMAC-SHA256
};

inline DerivedKeys deriveKeys(const std::string& password,
                                const std::vector<uint8_t>& salt,
                                uint32_t iterations = PBKDF2_ITERATIONS) {
    std::vector<uint8_t> combined = PBKDF2::deriveKey(password, salt, iterations, DERIVED_KEY_TOTAL_LENGTH_BYTES);

    DerivedKeys keys;
    keys.encryptionKey.assign(combined.begin(), combined.begin() + AES_KEY_LENGTH_BYTES);
    keys.macKey.assign(combined.begin() + AES_KEY_LENGTH_BYTES, combined.end());

    return keys;
}

// Codifica un entero de 32 bits como 4 bytes big-endian, para incluirlo de forma
// inequívoca (y sin ambigüedad de formato de texto) en los datos que autentica el HMAC.
inline std::array<uint8_t, 4> uint32ToBigEndianBytes(uint32_t value) {
    return {
        static_cast<uint8_t>(value >> 24),
        static_cast<uint8_t>(value >> 16),
        static_cast<uint8_t>(value >> 8),
        static_cast<uint8_t>(value)
    };
}

// Construye el buffer exacto sobre el que se calcula el HMAC: todo lo que un atacante
// podría intentar manipular sin conocer la contraseña (IV, salt, iterations, ciphertext).
// Es importante que salt e iterations también estén autenticados: si no lo estuvieran,
// un atacante podría, por ejemplo, rebajar "iterations" para debilitar futuros intentos
// de fuerza bruta sin que decrypt() lo detecte.
inline std::vector<uint8_t> buildAuthenticatedData(const std::vector<uint8_t>& iv,
                                                      const std::vector<uint8_t>& salt,
                                                      uint32_t iterations,
                                                      const std::vector<uint8_t>& ciphertext) {
    std::vector<uint8_t> data;
    data.reserve(iv.size() + salt.size() + 4 + ciphertext.size());

    data.insert(data.end(), iv.begin(), iv.end());
    data.insert(data.end(), salt.begin(), salt.end());

    std::array<uint8_t, 4> iterBytes = uint32ToBigEndianBytes(iterations);
    data.insert(data.end(), iterBytes.begin(), iterBytes.end());

    data.insert(data.end(), ciphertext.begin(), ciphertext.end());

    return data;
}

// NOTA (punto 2 de la revisión, ya resuelto): la generación de bytes aleatorios
// ya no depende de std::random_device + std::mt19937 (cuya idoneidad criptográfica
// no está garantizada por el estándar, y es dudosa en algunos entornos MinGW).
// Se apoya en secure_random.h, que usa el CSPRNG nativo del sistema operativo
// (BCryptGenRandom en Windows, getrandom()//dev-urandom en Linux). Se reutiliza
// tanto para el IV/nonce de CTR como para la sal de PBKDF2.
inline std::vector<uint8_t> generate_random_bytes(size_t length = 16) {
    return SecureRandom::generate(length);
}

inline void encrypt(const std::string& path, const std::string& message, const std::string& password) {
    std::vector<uint8_t> salt = generate_random_bytes(SALT_LENGTH_BYTES);
    DerivedKeys keys = deriveKeys(password, salt);
    std::vector<uint8_t> iv = generate_random_bytes(16); // IV/nonce de CTR: 16 bytes (tamaño de bloque de AES)

    // CTR no requiere padding: el buffer a cifrar tiene exactamente la longitud del mensaje.
    std::vector<uint8_t> encrypted(message.begin(), message.end());

    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, keys.encryptionKey.data(), iv.data());
    AES_CTR_xcrypt_buffer(&ctx, encrypted.data(), encrypted.size());

    // Encrypt-then-MAC: el HMAC se calcula sobre el ciphertext ya cifrado, junto con
    // iv/salt/iterations, usando la clave de MAC (independiente de la de cifrado).
    std::vector<uint8_t> authData = buildAuthenticatedData(iv, salt, PBKDF2_ITERATIONS, encrypted);
    std::array<uint8_t, 32> mac = HMAC_SHA256::compute(keys.macKey, authData);
    std::vector<uint8_t> macVec(mac.begin(), mac.end());

    std::string output = toHexString(encrypted) + '|' +
                          toHexString(iv) + '|' +
                          toHexString(salt) + '|' +
                          std::to_string(PBKDF2_ITERATIONS) + '|' +
                          toHexString(macVec);

    std::ofstream out(path);
    if(out.is_open()) {
        out << output;
        out.close();
    } else {
        throw std::runtime_error(T(Str::SaveFileErrorMessage));
    }
}

inline void encrypt(const std::string& path, const std::vector<uint8_t>& content, const std::string& password) {
    std::vector<uint8_t> salt = generate_random_bytes(SALT_LENGTH_BYTES);
    DerivedKeys keys = deriveKeys(password, salt);
    std::vector<uint8_t> iv = generate_random_bytes(16); // IV/nonce de CTR: 16 bytes (tamaño de bloque de AES)

    // CTR no requiere padding: el buffer a cifrar tiene exactamente la longitud del mensaje.
    std::vector<uint8_t> encrypted(content.begin(), content.end());

    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, keys.encryptionKey.data(), iv.data());
    AES_CTR_xcrypt_buffer(&ctx, encrypted.data(), encrypted.size());

    // Encrypt-then-MAC: el HMAC se calcula sobre el ciphertext ya cifrado, junto con
    // iv/salt/iterations, usando la clave de MAC (independiente de la de cifrado).
    std::vector<uint8_t> authData = buildAuthenticatedData(iv, salt, PBKDF2_ITERATIONS, encrypted);
    std::array<uint8_t, 32> mac = HMAC_SHA256::compute(keys.macKey, authData);
    std::vector<uint8_t> macVec(mac.begin(), mac.end());

    std::string output = toHexString(encrypted) + '|' +
                          toHexString(iv) + '|' +
                          toHexString(salt) + '|' +
                          std::to_string(PBKDF2_ITERATIONS) + '|' +
                          toHexString(macVec);

    std::ofstream out(path);
    if(out.is_open()) {
        out << output;
        out.close();
    } else {
        throw std::runtime_error(T(Str::SaveFileErrorMessage));
    }
}


// Constante que TÚ decides y documentas. Si quieres reproducir el comando exacto
// que diste al principio (sin -iter explícito), usa 10000. Si prefieres más
// seguridad y estás dispuesto a exigir siempre "-iter 300000" al usar openssl,
// usa un valor más alto.
constexpr uint32_t OPENSSL_COMPAT_ITERATIONS = 10000;
constexpr size_t OPENSSL_SALT_LENGTH_BYTES = 8;   // OpenSSL usa 8 bytes, no 16
constexpr size_t OPENSSL_DERIVED_LENGTH_BYTES = 48; // 32 (key) + 16 (iv)

inline void encryptOpenSSLCompatible(const std::string& path,
                                       const std::vector<uint8_t>& content,
                                       const std::string& password) {
    std::vector<uint8_t> salt = generate_random_bytes(OPENSSL_SALT_LENGTH_BYTES);

    std::vector<uint8_t> derived = PBKDF2::deriveKey(password, salt,
                                                        OPENSSL_COMPAT_ITERATIONS,
                                                        OPENSSL_DERIVED_LENGTH_BYTES);
    std::vector<uint8_t> key(derived.begin(), derived.begin() + 32);
    std::vector<uint8_t> iv(derived.begin() + 32, derived.end()); // 16 bytes

    std::vector<uint8_t> encrypted(content.begin(), content.end());

    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, key.data(), iv.data());
    AES_CTR_xcrypt_buffer(&ctx, encrypted.data(), encrypted.size());

    std::ofstream out(path, std::ios::binary);
    if (!out.is_open()) throw std::runtime_error(T(Str::SaveFileErrorMessage));

    out.write("Salted__", 8);
    out.write(reinterpret_cast<const char*>(salt.data()), salt.size());
    out.write(reinterpret_cast<const char*>(encrypted.data()), encrypted.size());
}

inline void encryptOpenSSLCompatible(const std::string& path,
                                       const std::string& message,
                                       const std::string& password) {
	std::vector<uint8_t> content(message.begin(), message.end());
	encryptOpenSSLCompatible(path, content, password);
}

// For normal mode
inline void decrypt(const std::string& inputFilePath, const std::string& outputFilePath, const std::string& password) {
    std::ifstream in(inputFilePath);
    std::string encryptedTextLine;
    if(in.is_open()) {
        std::getline(in, encryptedTextLine);
        in.close();
    } else {
        throw std::runtime_error(T(Str::LoadFileErrorMessage));
    }

    std::vector<std::string> tokens = split(encryptedTextLine, '|');

    // Formato actual: ciphertext|iv|salt|iterations|mac
    if(tokens.size() != 5) {
        throw std::runtime_error(T(Str::InvalidFileFormatErrorMessage));
    }

    const std::string& encryptedMessageHex = tokens[0];
    const std::string& ivHex = tokens[1];
    const std::string& saltHex = tokens[2];
    uint32_t iterations = static_cast<uint32_t>(std::stoul(tokens[3]));
    const std::string& macHex = tokens[4];

    std::vector<uint8_t> encrypted = fromHexString(encryptedMessageHex);
    std::vector<uint8_t> iv = fromHexString(ivHex);
    std::vector<uint8_t> salt = fromHexString(saltHex);
    std::vector<uint8_t> receivedMac = fromHexString(macHex);

    DerivedKeys keys;

    if(iterations > MAX_ALLOWED_ITERATIONS) {
        throw std::runtime_error(T(Str::MaxIterationsErrorMessage));
    } else {
        keys = deriveKeys(password, salt, iterations);
    }

    // Verificacion de integridad ANTES de descifrar (encrypt-then-MAC): si el MAC no
    // coincide, ni siquiera se intenta descifrar el contenido. Esto cubre dos casos a
    // la vez: contraseña incorrecta (la clave de MAC derivada seria distinta) y
    // manipulacion del fichero (ciphertext, iv, salt o iterations alterados).
    std::vector<uint8_t> authData = buildAuthenticatedData(iv, salt, iterations, encrypted);
    std::array<uint8_t, 32> expectedMac = HMAC_SHA256::compute(keys.macKey, authData);
    std::vector<uint8_t> expectedMacVec(expectedMac.begin(), expectedMac.end());

    if (!constantTimeEquals(receivedMac, expectedMacVec)) {
        throw std::runtime_error(T(Str::IntegrityCheckErrorMessage));
    }

    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, keys.encryptionKey.data(), iv.data());
    // CTR usa la misma función tanto para cifrar como para descifrar (es XOR con el keystream)
    AES_CTR_xcrypt_buffer(&ctx, encrypted.data(), encrypted.size());

    // Sin padding que retirar: el resultado ya es el mensaje original completo.
    if(!guardarFichero(outputFilePath, encrypted)) {
        throw std::runtime_error(T(Str::SaveFileErrorMessage));
    }
}

// For plaintext mode
inline std::string decrypt(const std::string& inputFilePath, const std::string& password) {
    std::ifstream in(inputFilePath);
    std::string encryptedTextLine;
    if(in.is_open()) {
        std::getline(in, encryptedTextLine);
        in.close();
    } else {
        throw std::runtime_error(T(Str::LoadFileErrorMessage));
    }

    std::vector<std::string> tokens = split(encryptedTextLine, '|');

    // Formato actual: ciphertext|iv|salt|iterations|mac
    if(tokens.size() != 5) {
        throw std::runtime_error(T(Str::InvalidFileFormatErrorMessage));
    }

    const std::string& encryptedMessageHex = tokens[0];
    const std::string& ivHex = tokens[1];
    const std::string& saltHex = tokens[2];
    uint32_t iterations = static_cast<uint32_t>(std::stoul(tokens[3]));
    const std::string& macHex = tokens[4];

    std::vector<uint8_t> encrypted = fromHexString(encryptedMessageHex);
    std::vector<uint8_t> iv = fromHexString(ivHex);
    std::vector<uint8_t> salt = fromHexString(saltHex);
    std::vector<uint8_t> receivedMac = fromHexString(macHex);

    DerivedKeys keys;

    if(iterations > MAX_ALLOWED_ITERATIONS) {
        throw std::runtime_error(T(Str::MaxIterationsErrorMessage));
    } else {
        keys = deriveKeys(password, salt, iterations);
    }

    // Verificacion de integridad ANTES de descifrar (encrypt-then-MAC): si el MAC no
    // coincide, ni siquiera se intenta descifrar el contenido. Esto cubre dos casos a
    // la vez: contraseña incorrecta (la clave de MAC derivada seria distinta) y
    // manipulacion del fichero (ciphertext, iv, salt o iterations alterados).
    std::vector<uint8_t> authData = buildAuthenticatedData(iv, salt, iterations, encrypted);
    std::array<uint8_t, 32> expectedMac = HMAC_SHA256::compute(keys.macKey, authData);
    std::vector<uint8_t> expectedMacVec(expectedMac.begin(), expectedMac.end());

    if (!constantTimeEquals(receivedMac, expectedMacVec)) {
        throw std::runtime_error(T(Str::IntegrityCheckErrorMessage));
    }

    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, keys.encryptionKey.data(), iv.data());
    // CTR usa la misma función tanto para cifrar como para descifrar (es XOR con el keystream)
    AES_CTR_xcrypt_buffer(&ctx, encrypted.data(), encrypted.size());

    // Sin padding que retirar: el resultado ya es el mensaje original completo.
    return std::string(encrypted.begin(), encrypted.end());
}

// For normal mode
inline void decryptOpenSSLCompatible(const std::string& inputPath, const std::string& outputPath,
                                                        const std::string& password) {
    std::ifstream in(inputPath, std::ios::binary);
    if (!in.is_open()) throw std::runtime_error(T(Str::LoadFileErrorMessage));

    std::vector<uint8_t> data((std::istreambuf_iterator<char>(in)),
                                 std::istreambuf_iterator<char>());

    if (data.size() < 16 || std::memcmp(data.data(), "Salted__", 8) != 0) {
        throw std::runtime_error(T(Str::InvalidFileFormatErrorMessage));
    }

    std::vector<uint8_t> salt(data.begin() + 8, data.begin() + 16);
    std::vector<uint8_t> ciphertext(data.begin() + 16, data.end());

    std::vector<uint8_t> derived = PBKDF2::deriveKey(password, salt,
                                                        OPENSSL_COMPAT_ITERATIONS,
                                                        OPENSSL_DERIVED_LENGTH_BYTES);
    std::vector<uint8_t> key(derived.begin(), derived.begin() + 32);
    std::vector<uint8_t> iv(derived.begin() + 32, derived.end());

    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, key.data(), iv.data());
    AES_CTR_xcrypt_buffer(&ctx, ciphertext.data(), ciphertext.size());
    
    std::ofstream out(outputPath, std::ios::binary);
    if (!out.is_open()) throw std::runtime_error(T(Str::SaveFileErrorMessage));

    out.write(reinterpret_cast<const char*>(ciphertext.data()), ciphertext.size());
}

// For plaintext mode
inline std::string decryptOpenSSLCompatible(const std::string& path,
                                                        const std::string& password) {
    std::ifstream in(path, std::ios::binary);
    if (!in.is_open()) throw std::runtime_error(T(Str::LoadFileErrorMessage));

    std::vector<uint8_t> data((std::istreambuf_iterator<char>(in)),
                                 std::istreambuf_iterator<char>());

    if (data.size() < 16 || std::memcmp(data.data(), "Salted__", 8) != 0) {
        throw std::runtime_error(T(Str::InvalidFileFormatErrorMessage));
    }

    std::vector<uint8_t> salt(data.begin() + 8, data.begin() + 16);
    std::vector<uint8_t> ciphertext(data.begin() + 16, data.end());

    std::vector<uint8_t> derived = PBKDF2::deriveKey(password, salt,
                                                        OPENSSL_COMPAT_ITERATIONS,
                                                        OPENSSL_DERIVED_LENGTH_BYTES);
    std::vector<uint8_t> key(derived.begin(), derived.begin() + 32);
    std::vector<uint8_t> iv(derived.begin() + 32, derived.end());

    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, key.data(), iv.data());
    AES_CTR_xcrypt_buffer(&ctx, ciphertext.data(), ciphertext.size());

	return std::string(ciphertext.begin(), ciphertext.end()); // ya es el texto plano, sin verificación de integridad posible
}
