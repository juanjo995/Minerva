// pbkdf2.h
//
// Implementación de PBKDF2-HMAC-SHA256 (RFC 8018 / NIST SP 800-132),
// construida sobre hmac_sha256.h. Sin dependencias externas.
//
// Uso básico:
//
//     std::vector<uint8_t> key = PBKDF2::deriveKey(password, salt, iterations, keyLength);
//
// - password: la contraseña del usuario (std::string).
// - salt: bytes aleatorios generados una vez por operación de cifrado (no secretos).
// - iterations: factor de coste (ej. 300000).
// - keyLength: longitud deseada de la clave derivada, en bytes (ej. 32 para AES-256).

#pragma once

#include "hmac_sha256.h"
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>

namespace PBKDF2 {

namespace detail {

    constexpr size_t HASH_LEN = 32; // Tamaño de salida de HMAC-SHA256, en bytes

    // Codifica un entero de 32 bits como 4 bytes big-endian (INT(i) en la notación del RFC 8018)
    inline std::array<uint8_t, 4> intToBigEndianBytes(uint32_t i) {
        return {
            static_cast<uint8_t>(i >> 24),
            static_cast<uint8_t>(i >> 16),
            static_cast<uint8_t>(i >> 8),
            static_cast<uint8_t>(i)
        };
    }

    // Calcula un único bloque T_i = F(password, salt, iterations, i), según RFC 8018:
    //   U1 = HMAC(password, salt || INT(i))
    //   U2 = HMAC(password, U1)
    //   ...
    //   Uc = HMAC(password, U_{c-1})
    //   T_i = U1 XOR U2 XOR ... XOR Uc
    inline std::array<uint8_t, HASH_LEN> computeBlock(const std::vector<uint8_t>& password,
                                                        const std::vector<uint8_t>& salt,
                                                        uint32_t iterations,
                                                        uint32_t blockIndex) {
        // U1 = HMAC(password, salt || INT(blockIndex))
        std::vector<uint8_t> saltWithIndex = salt;
        std::array<uint8_t, 4> indexBytes = intToBigEndianBytes(blockIndex);
        saltWithIndex.insert(saltWithIndex.end(), indexBytes.begin(), indexBytes.end());

        std::array<uint8_t, HASH_LEN> u = HMAC_SHA256::compute(password, saltWithIndex);
        std::array<uint8_t, HASH_LEN> t = u; // acumulador del XOR (T_i)

        // U2 .. Uc
        for (uint32_t iter = 2; iter <= iterations; iter++) {
            std::vector<uint8_t> prevU(u.begin(), u.end());
            u = HMAC_SHA256::compute(password, prevU);

            for (size_t j = 0; j < HASH_LEN; j++) {
                t[j] ^= u[j];
            }
        }

        return t;
    }

} // namespace detail

// API pública: deriva una clave de longitud arbitraria a partir de una contraseña y una sal
inline std::vector<uint8_t> deriveKey(const std::vector<uint8_t>& password,
                                        const std::vector<uint8_t>& salt,
                                        uint32_t iterations,
                                        size_t keyLength) {
    using namespace detail;

    std::vector<uint8_t> derivedKey;
    derivedKey.reserve(keyLength);

    // Número de bloques de HASH_LEN bytes necesarios para cubrir keyLength (redondeo hacia arriba)
    uint32_t numBlocks = static_cast<uint32_t>((keyLength + HASH_LEN - 1) / HASH_LEN);

    for (uint32_t blockIndex = 1; blockIndex <= numBlocks; blockIndex++) {
        std::array<uint8_t, HASH_LEN> block = computeBlock(password, salt, iterations, blockIndex);
        derivedKey.insert(derivedKey.end(), block.begin(), block.end());
    }

    derivedKey.resize(keyLength); // recorta el sobrante si keyLength no es múltiplo exacto de HASH_LEN
    return derivedKey;
}

inline std::vector<uint8_t> deriveKey(const std::string& password,
                                        const std::vector<uint8_t>& salt,
                                        uint32_t iterations,
                                        size_t keyLength) {
    std::vector<uint8_t> passwordBytes(password.begin(), password.end());
    return deriveKey(passwordBytes, salt, iterations, keyLength);
}

} // namespace PBKDF2
