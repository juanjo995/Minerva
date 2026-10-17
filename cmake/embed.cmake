# Uso: cmake -DINPUT=... -DOUTPUT=... -DNAME=... -P embed.cmake
file(READ "${INPUT}" hex HEX)
string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1," arr "${hex}")
file(WRITE "${OUTPUT}"
"#include <cstddef>\n"
"extern const unsigned char ${NAME}[];\n"
"extern const std::size_t ${NAME}_size;\n"
"alignas(16) const unsigned char ${NAME}[] = {${arr}};\n"
"const std::size_t ${NAME}_size = sizeof(${NAME});\n")