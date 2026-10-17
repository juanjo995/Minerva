// secure_random.h
//
// Generación de bytes aleatorios criptográficamente seguros (CSPRNG),
// respaldada por la fuente de entropía nativa del sistema operativo:
//
//   - Windows: BCryptGenRandom (Windows CNG)
//   - Linux:   getrandom() (syscall del kernel), con /dev/urandom como respaldo
//   - macOS:   arc4random_buf() (CSPRNG del sistema, basado en ChaCha20)
//
// A diferencia de std::random_device + std::mt19937 (cuya idoneidad
// criptográfica no está garantizada por el estándar de C++), esta
// implementación se apoya directamente en el generador criptográfico
// que el propio sistema operativo mantiene y audita.
//
// Uso básico:
//
//     std::vector<uint8_t> bytes = SecureRandom::generate(16);

#pragma once

#include <cstdint>
#include <vector>
#include <stdexcept>
#include <string>

#ifdef _WIN32
    #include <windows.h>
    #include <bcrypt.h>
    #pragma comment(lib, "Bcrypt.lib")
#elif defined(__linux__)
    #include <sys/random.h>
    #include <cerrno>
    #include <cstring>
    #include <fstream>
#elif defined(__APPLE__)
    #include <cstdlib>
#endif

namespace SecureRandom {

#ifdef _WIN32

inline std::vector<uint8_t> generate(size_t length) {
    std::vector<uint8_t> buffer(length);

    NTSTATUS status = BCryptGenRandom(
        NULL,                              // Algoritmo por defecto del sistema (RNG criptográfico)
        buffer.data(),
        static_cast<ULONG>(length),
        BCRYPT_USE_SYSTEM_PREFERRED_RNG     // Usa el RNG preferido del sistema, sin necesidad de abrir un handle de algoritmo
    );

    if (!BCRYPT_SUCCESS(status)) {
        throw std::runtime_error("Error: BCryptGenRandom failed with code: " + std::to_string(status));
    }

    return buffer;
}

#elif defined(__linux__)

inline std::vector<uint8_t> generate(size_t length) {
    std::vector<uint8_t> buffer(length);
    size_t totalRead = 0;

    // getrandom() puede devolver menos bytes de los pedidos si la llamada es
    // interrumpida por una señal; por eso se repite hasta completar el buffer.
    while (totalRead < length) {
        ssize_t result = getrandom(buffer.data() + totalRead, length - totalRead, 0);

        if (result < 0) {
            if (errno == EINTR) {
                continue; // Interrumpido por una señal, reintentar
            }
            if (errno == ENOSYS) {
                break; // getrandom() no disponible en este kernel -> usar el respaldo de /dev/urandom
            }
            throw std::runtime_error(std::string("Error: getrandom() failed: ") + std::strerror(errno));
            //throw std::runtime_error(std::string("Error: getrandom() fallo: ") + std::strerror(errno));
        }

        totalRead += static_cast<size_t>(result);
    }

    if (totalRead == length) {
        return buffer;
    }

    // Respaldo: /dev/urandom (kernels muy antiguos sin getrandom(), antes de Linux 3.17)
    std::ifstream urandom("/dev/urandom", std::ios::binary);
    if (!urandom.is_open()) {
        throw std::runtime_error("Error: /dev/urandom could not be opened");
        //throw std::runtime_error("Error: No se pudo abrir /dev/urandom");
    }

    urandom.read(reinterpret_cast<char*>(buffer.data()), static_cast<std::streamsize>(length));
    if (!urandom) {
        throw std::runtime_error("Error: Incomplete reading of /dev/urandom");
        //throw std::runtime_error("Error: Lectura incompleta de /dev/urandom");
    }

    return buffer;
}

#elif defined(__APPLE__)

inline std::vector<uint8_t> generate(size_t length) {
    std::vector<uint8_t> buffer(length);

    // arc4random_buf() usa el CSPRNG del sistema (basado en ChaCha20),
    // sembrado y resembrado automaticamente por el kernel a partir de
    // fuentes de entropia del hardware. A diferencia de getrandom() o
    // BCryptGenRandom, no devuelve codigo de error: por diseño, siempre
    // tiene exito (bloquea internamente si el generador aun no esta
    // listo, en vez de fallar), por lo que no hace falta ningun bucle
    // de reintento ni comprobacion de estado.
    arc4random_buf(buffer.data(), length);

    return buffer;
}

#else
    #error "SecureRandom: unsupported platform. A specific implementation is required for this operating system."
    //#error "SecureRandom: plataforma no soportada. Se requiere una implementacion especifica para este sistema operativo."
#endif

} // namespace SecureRandom
