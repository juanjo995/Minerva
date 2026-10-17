// secure_memory.h
// Borrado seguro de datos sensibles en memoria.
//
//   secureWipe(ptr, n)  -> pone a cero n bytes sin que el compilador lo elimine
//   wipe(str) / wipe(vec) -> borra el contenido (incluida la capacidad sobrante) y libera
//   SecureString / SecureBytes -> contenedores que ponen a cero cada bloque de memoria
//                                 antes de liberarlo (también en las realocaciones)

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#if defined(_WIN32)
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif
    #include <windows.h>
#endif

// Pone a cero 'n' bytes de forma que el optimizador no pueda eliminar la escritura.
inline void secureWipe(void* p, std::size_t n) noexcept
{
    if (!p || n == 0) return;
#if defined(_WIN32)
    SecureZeroMemory(p, n);
#elif defined(__GNUC__) || defined(__clang__)
    std::memset(p, 0, n);
    // Barrera: el compilador debe asumir que la memoria se lee después,
    // así que no puede descartar el memset.
    __asm__ __volatile__("" : : "r"(p) : "memory");
#else
    volatile unsigned char* vp = static_cast<volatile unsigned char*>(p);
    while (n--) *vp++ = 0;
#endif
}

// Allocator que pone a cero la memoria antes de devolverla al sistema.
// Cubre también las copias antiguas que quedan al crecer el contenedor.
template <class T>
struct SecureAllocator
{
    using value_type = T;

    SecureAllocator() noexcept = default;
    template <class U> SecureAllocator(const SecureAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) { return std::allocator<T>{}.allocate(n); }

    void deallocate(T* p, std::size_t n) noexcept
    {
        secureWipe(p, n * sizeof(T));
        std::allocator<T>{}.deallocate(p, n);
    }

    template <class U> bool operator==(const SecureAllocator<U>&) const noexcept { return true; }
    template <class U> bool operator!=(const SecureAllocator<U>&) const noexcept { return false; }
};

using SecureString = std::basic_string<char, std::char_traits<char>, SecureAllocator<char>>;
using SecureBytes  = std::vector<std::uint8_t, SecureAllocator<std::uint8_t>>;

// Borra un string: también la parte entre size() y capacity() y el búfer interno
// de cadenas cortas (SSO), que el allocator no llega a ver.
template <class Traits, class Alloc>
inline void wipe(std::basic_string<char, Traits, Alloc>& s) noexcept
{
    s.resize(s.capacity());          // no realoca: solo expone la capacidad ya reservada
    secureWipe(&s[0], s.size());
    s.clear();
    s.shrink_to_fit();
}

// Borra un vector de tipos triviales (bytes, enteros...).
template <class T, class Alloc>
inline void wipe(std::vector<T, Alloc>& v) noexcept
{
    static_assert(std::is_trivially_copyable<T>::value,
                  "wipe() solo admite vectores de tipos triviales");
    v.resize(v.capacity());          // no realoca
    secureWipe(v.data(), v.size() * sizeof(T));
    v.clear();
    v.shrink_to_fit();
}
