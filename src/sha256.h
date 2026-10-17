// sha256.h
//
// Implementación standalone de SHA-256 (FIPS 180-4), sin dependencias externas.
// Pensada para usarse como base de HMAC-SHA256 y PBKDF2-HMAC-SHA256.
//
// Uso básico:
//
//     std::vector<uint8_t> digest = SHA256::hash(data);
//
// El resultado siempre tiene 32 bytes (256 bits).

#pragma once

#include <cstdint>
#include <cstring>
#include <vector>
#include <string>
#include <array>

namespace SHA256 {

namespace detail {

    // Rotación circular a la derecha (operación básica usada por SHA-256)
    inline uint32_t rotr(uint32_t x, uint32_t n) {
        return (x >> n) | (x << (32 - n));
    }

    // Constantes de ronda K, los primeros 32 bits de las partes fraccionarias
    // de las raíces cúbicas de los primeros 64 números primos (definidas por el estándar FIPS 180-4)
    constexpr uint32_t K[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    struct Context {
        uint32_t state[8] = {
            // Valores iniciales del hash, primeros 32 bits de las partes fraccionarias
            // de las raíces cuadradas de los primeros 8 números primos
            0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
            0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
        };
        uint8_t buffer[64] = {0};
        size_t bufferLength = 0;
        uint64_t totalLength = 0; // longitud total del mensaje en bytes
    };

    // Procesa un único bloque de 64 bytes, actualizando el estado interno
    inline void processBlock(Context& ctx, const uint8_t* block) {
        uint32_t w[64];

        // Los primeros 16 words se toman directamente del bloque (big-endian)
        for (int i = 0; i < 16; i++) {
            w[i] = (static_cast<uint32_t>(block[i * 4]) << 24) |
                   (static_cast<uint32_t>(block[i * 4 + 1]) << 16) |
                   (static_cast<uint32_t>(block[i * 4 + 2]) << 8) |
                   (static_cast<uint32_t>(block[i * 4 + 3]));
        }

        // Expansión del resto de words (message schedule)
        for (int i = 16; i < 64; i++) {
            uint32_t s0 = rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18) ^ (w[i - 15] >> 3);
            uint32_t s1 = rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19) ^ (w[i - 2] >> 10);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }

        uint32_t a = ctx.state[0];
        uint32_t b = ctx.state[1];
        uint32_t c = ctx.state[2];
        uint32_t d = ctx.state[3];
        uint32_t e = ctx.state[4];
        uint32_t f = ctx.state[5];
        uint32_t g = ctx.state[6];
        uint32_t h = ctx.state[7];

        for (int i = 0; i < 64; i++) {
            uint32_t S1 = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = h + S1 + ch + K[i] + w[i];
            uint32_t S0 = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        ctx.state[0] += a;
        ctx.state[1] += b;
        ctx.state[2] += c;
        ctx.state[3] += d;
        ctx.state[4] += e;
        ctx.state[5] += f;
        ctx.state[6] += g;
        ctx.state[7] += h;
    }

    inline void update(Context& ctx, const uint8_t* data, size_t length) {
        ctx.totalLength += length;

        while (length > 0) {
            size_t toCopy = 64 - ctx.bufferLength;
            if (toCopy > length) toCopy = length;

            std::memcpy(ctx.buffer + ctx.bufferLength, data, toCopy);
            ctx.bufferLength += toCopy;
            data += toCopy;
            length -= toCopy;

            if (ctx.bufferLength == 64) {
                processBlock(ctx, ctx.buffer);
                ctx.bufferLength = 0;
            }
        }
    }

    inline std::array<uint8_t, 32> finalize(Context& ctx) {
        uint64_t bitLength = ctx.totalLength * 8;

        // Padding: byte 0x80, seguido de ceros, dejando 8 bytes al final para la longitud
        uint8_t padByte = 0x80;
        update(ctx, &padByte, 1);

        uint8_t zero = 0x00;
        while (ctx.bufferLength != 56) {
            update(ctx, &zero, 1);
        }

        // Longitud del mensaje original en bits, big-endian, 8 bytes
        uint8_t lengthBytes[8];
        for (int i = 0; i < 8; i++) {
            lengthBytes[i] = static_cast<uint8_t>(bitLength >> (56 - i * 8));
        }

        // Insertamos la longitud directamente (sin pasar por update para no
        // interferir con el conteo de totalLength, ya congelado)
        std::memcpy(ctx.buffer + ctx.bufferLength, lengthBytes, 8);
        processBlock(ctx, ctx.buffer);

        std::array<uint8_t, 32> digest;
        for (int i = 0; i < 8; i++) {
            digest[i * 4]     = static_cast<uint8_t>(ctx.state[i] >> 24);
            digest[i * 4 + 1] = static_cast<uint8_t>(ctx.state[i] >> 16);
            digest[i * 4 + 2] = static_cast<uint8_t>(ctx.state[i] >> 8);
            digest[i * 4 + 3] = static_cast<uint8_t>(ctx.state[i]);
        }

        return digest;
    }

} // namespace detail

// API pública: calcula el hash SHA-256 de un bloque de datos arbitrario
inline std::array<uint8_t, 32> getHash(const uint8_t* data, size_t length) {
    detail::Context ctx;
    detail::update(ctx, data, length);
    return detail::finalize(ctx);
}

inline std::array<uint8_t, 32> getHash(const std::vector<uint8_t>& data) {
    return getHash(data.data(), data.size());
}

inline std::array<uint8_t, 32> getHash(const std::string& data) {
    return getHash(reinterpret_cast<const uint8_t*>(data.data()), data.size());
}

} // namespace SHA256
