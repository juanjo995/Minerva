// hmac_sha256.h
//
// Implementación de HMAC-SHA256 (RFC 2104 / FIPS 198-1), construida sobre sha256.h.
// Sin dependencias externas más allá de sha256.h.
//
// Uso básico:
//
//     std::array<uint8_t, 32> mac = HMAC_SHA256::compute(key, message);

#pragma once

#include "sha256.h"
#include <cstdint>
#include <vector>
#include <string>
#include <array>

namespace HMAC_SHA256 {

namespace detail {

    constexpr size_t BLOCK_SIZE = 64;  // Tamaño de bloque interno de SHA-256, en bytes
    constexpr size_t DIGEST_SIZE = 32; // Tamaño de salida de SHA-256, en bytes

    // Ajusta la clave para que tenga exactamente BLOCK_SIZE bytes:
    // - Si es más larga que el bloque, se pre-hashea (SHA-256 la reduce a 32 bytes).
    // - Si es más corta (o tras el hasheo anterior), se rellena con ceros hasta BLOCK_SIZE.
    inline std::array<uint8_t, BLOCK_SIZE> adjustKey(const uint8_t* key, size_t keyLength) {
        std::array<uint8_t, BLOCK_SIZE> adjusted{}; // inicializado a ceros

        if (keyLength > BLOCK_SIZE) {
            std::array<uint8_t, DIGEST_SIZE> hashedKey = SHA256::getHash(key, keyLength);
            std::copy(hashedKey.begin(), hashedKey.end(), adjusted.begin());
        } else {
            std::copy(key, key + keyLength, adjusted.begin());
        }

        return adjusted;
    }

} // namespace detail

// API pública: calcula HMAC-SHA256(key, message)
inline std::array<uint8_t, 32> compute(const uint8_t* key, size_t keyLength,
                                         const uint8_t* message, size_t messageLength) {
    using namespace detail;

    std::array<uint8_t, BLOCK_SIZE> keyBlock = adjustKey(key, keyLength);

    // Preparamos ipad y opad: XOR de la clave ajustada con los patrones fijos del estándar
    std::array<uint8_t, BLOCK_SIZE> innerKeyPad;
    std::array<uint8_t, BLOCK_SIZE> outerKeyPad;
    for (size_t i = 0; i < BLOCK_SIZE; i++) {
        innerKeyPad[i] = keyBlock[i] ^ 0x36;
        outerKeyPad[i] = keyBlock[i] ^ 0x5c;
    }

    // Hash interno: H( (key XOR ipad) || message )
    SHA256::detail::Context innerCtx;
    SHA256::detail::update(innerCtx, innerKeyPad.data(), innerKeyPad.size());
    SHA256::detail::update(innerCtx, message, messageLength);
    std::array<uint8_t, DIGEST_SIZE> innerHash = SHA256::detail::finalize(innerCtx);

    // Hash externo: H( (key XOR opad) || innerHash )
    SHA256::detail::Context outerCtx;
    SHA256::detail::update(outerCtx, outerKeyPad.data(), outerKeyPad.size());
    SHA256::detail::update(outerCtx, innerHash.data(), innerHash.size());
    std::array<uint8_t, DIGEST_SIZE> result = SHA256::detail::finalize(outerCtx);

    return result;
}

inline std::array<uint8_t, 32> compute(const std::vector<uint8_t>& key, const std::vector<uint8_t>& message) {
    return compute(key.data(), key.size(), message.data(), message.size());
}

/*inline std::array<uint8_t, 32> compute(const std::string& key, const std::string& message) {
    return compute(reinterpret_cast<const uint8_t*>(key.data()), key.size(),
                    reinterpret_cast<const uint8_t*>(message.data()), message.size());
}

inline std::array<uint8_t, 32> compute(const std::vector<uint8_t>& key, const std::string& message) {
    return compute(key.data(), key.size(),
                    reinterpret_cast<const uint8_t*>(message.data()), message.size());
}*/

} // namespace HMAC_SHA256
