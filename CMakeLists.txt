cmake_minimum_required(VERSION 3.15)

# Dos formas distintas de hacer lo mismo
set(CMAKE_POLICY_VERSION_MINIMUM "3.5" CACHE STRING "")
#set(ENV{CMAKE_POLICY_VERSION_MINIMUM} "3.5")

# Debe ir ANTES de project(), necesario para MSVC
# No requiere estar dentro de un if(MSVC) porque las variables MSVC, WIN32, APPLE, UNIX... etc. se crean después de la llamada a project()
# Y no afecta para nada al resto de SSOO o compiladores
cmake_policy(SET CMP0091 NEW)

if(NOT APPLE)
project(Minerva VERSION 1.0 LANGUAGES C CXX)
else()
project(Minerva VERSION 1.0 LANGUAGES C CXX OBJC) # On macOS we need OBJC
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

# =====================================================================
# stb_image (single-header; se descarga el .h directamente, sin git)
# =====================================================================
set(STB_IMAGE_DIR ${CMAKE_BINARY_DIR}/_deps/stb-src)
file(MAKE_DIRECTORY ${STB_IMAGE_DIR})

file(DOWNLOAD
    # https://github.com/nothings/stb/blob/master/stb_image.h
    https://raw.githubusercontent.com/nothings/stb/5c205738c191bcb0abc65c4febfa9bd25ff35234/stb_image.h
    ${STB_IMAGE_DIR}/stb_image.h
    EXPECTED_HASH SHA256=594c2fe35d49488b4382dbfaec8f98366defca819d916ac95becf3e75f4200b3
)

add_library(stb_image INTERFACE)
target_include_directories(stb_image INTERFACE ${STB_IMAGE_DIR})

# =====================================================================
# GLFW 3.5.1
# =====================================================================
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL        OFF CACHE BOOL "" FORCE)
if(UNIX AND NOT APPLE)
    # En Linux, evita depender del plugin de libdecor (decoraciones de
    # ventana en Wayland) forzando el uso de X11/XWayland, que siempre
    # obtiene la barra de título del gestor de ventanas sin necesidad
    # de paquetes extra en el sistema del usuario final.
    set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
endif()

FetchContent_Declare(
    glfw
    URL https://github.com/glfw/glfw/archive/refs/tags/3.5.1.zip
    URL_HASH SHA256=e9a80355e8a0c59b15ae8576c2c3aeae792c2b1082ec426dc93bde70d5017fda
)
FetchContent_MakeAvailable(glfw)
# Esto crea el target "glfw" listo para enlazar.

# =====================================================================
# GLAD genera su código fuente en tiempo de configuración con un
# script de Python que trae incluido el propio repositorio, por lo
# que necesitas tener Python 3 instalado en la máquina que compila.
# =====================================================================
FetchContent_Declare(
    glad
    URL https://github.com/Dav1dde/glad/archive/refs/tags/v2.0.8.zip
    URL_HASH SHA256=471886d363ea2b7e2f92081266c4775de91ee971a10359bd33559f1c5a1cbb92
)
FetchContent_MakeAvailable(glad)
add_subdirectory(${glad_SOURCE_DIR}/cmake ${glad_BINARY_DIR}/cmake_wrapper)

glad_add_library(glad_gl_core_33 STATIC REPRODUCIBLE API gl:core=3.3)
# Esto crea el target "glad_gl_core_33".

# =====================================================================
# Dear ImGui (no trae CMakeLists.txt propio -> lo construimos nosotros)
# =====================================================================
FetchContent_Declare(
    imgui
    URL https://github.com/ocornut/imgui/archive/refs/tags/v1.92.9b.zip
    URL_HASH SHA256=e1c46d676c2bcb7ced847ba27f50553e33a19db97b3cadaec7f8be64449139f8
)
FetchContent_MakeAvailable(imgui)

add_library(imgui STATIC
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC
    ${imgui_SOURCE_DIR}
    ${imgui_SOURCE_DIR}/backends
    ${imgui_SOURCE_DIR}/misc/cpp
)
target_link_libraries(imgui PUBLIC glfw)

# =====================================================================
# native-file-dialog-extended (sí trae CMakeLists.txt propio)
# =====================================================================
FetchContent_Declare(
    nfd
    URL https://github.com/btzy/nativefiledialog-extended/archive/refs/tags/v1.3.0.zip
    URL_HASH SHA256=d865b7bf4363fa6aac095b6cfb3b29912054306a18c8c596328fb2e9141c5391
)
FetchContent_MakeAvailable(nfd)
# Crea el target "nfd".

# =====================================================================
# tiny-AES-c (solo aes.c / aes.h, sin CMakeLists.txt)
# =====================================================================
FetchContent_Declare(
    tiny_aes
    URL https://github.com/kokke/tiny-AES-c/archive/refs/tags/v1.0.0.zip
    URL_HASH SHA256=b1c28e0f6bd77785faf078f4519955d17f6bceab4b235cd9df445f6f0a93f644
)
FetchContent_MakeAvailable(tiny_aes)

add_library(tiny_aes STATIC ${tiny_aes_SOURCE_DIR}/aes.c)
target_include_directories(tiny_aes PUBLIC ${tiny_aes_SOURCE_DIR})

# =====================================================================
# OpenGL del sistema (reemplaza la ruta a mano de OpenGL32.Lib)
# =====================================================================
find_package(OpenGL REQUIRED)

# =====================================================================
# Ejecutable
# =====================================================================
add_executable(main WIN32
    src/main.cpp
    src/GUI.cpp
    src/Strings.cpp
    src/AES.cpp
)

if(WIN32)
  enable_language(RC)
  target_sources(main PRIVATE ${CMAKE_SOURCE_DIR}/app.rc)
endif()

if(WIN32)
    target_compile_definitions(main PRIVATE NOMINMAX) # Windows define variables min y max que entran en conflicto con otras que estamos usando, hay que poner esta linea para arreglarlo
endif()

# Esto es para declarar el ejecutable como aplicación Windows
# Como usas WinMain en vez de main, necesitas decirle a CMake que este es un ejecutable WIN32 (subsistema /SUBSYSTEM:WINDOWS), si no, el linker espera un main() y falla, o te abre una consola detrás de tu GUI
if(WIN32)
    set_target_properties(main PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# UTF-8 en el código fuente, independientemente del compilador usado
if(MSVC)
    # Habilitar UTF-8 y habilitar excepciones de C++
    target_compile_options(main PRIVATE /utf-8 /EHsc)
else()
    # Esta linea no es estrictamente necesaria, con que el fichero donde tengamos definidos strings con caracteres raros esté en UTF8 sin BOM debería bastar
    target_compile_options(main PRIVATE -finput-charset=UTF-8)
endif()

target_link_libraries(main PRIVATE
    imgui
    glad_gl_core_33
    nfd
    tiny_aes
    stb_image
    OpenGL::GL
    glfw
)

if(UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
    target_link_libraries(main PRIVATE X11::X11)
endif()

if(WIN32 AND NOT MSVC) # Caso de MinGW
    # Aquí también podríamos poner Shell32, es solo que esa dependencia MinGW la resuelve automaticamente, pero MSVC no lo hace
    # Es decir, podriamos usar simplemente la linea del caso MSVC tanto para MSVC como para MinGW sin problemas
    # solo que para MinGW sería redundante
    target_link_libraries(main PRIVATE bcrypt)
elseif(WIN32 AND MSVC)
    target_link_libraries(main PRIVATE bcrypt Shell32)
endif()

# =====================================================================
# Enlazado estático
# =====================================================================
if(WIN32 AND NOT MSVC) # Caso de Windows usando MinGW
    message(STATUS "Configurando enlazado estático para Windows...")
    target_link_options(main PRIVATE
        -static-libgcc -static-libstdc++
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
    )
elseif(UNIX AND NOT APPLE)
    message(STATUS "Configurando enlazado mixto para Linux (evita error de libgtk-3.so)...")
    target_link_options(main PRIVATE -static-libgcc -static-libstdc++)
elseif(APPLE)
    message(STATUS "macOS: no se aplica static linking (AppleClang no lo soporta; libc++ ya viene con el sistema)")
    # Sin flags adicionales de enlazado estático
endif()

# =====================================================================
# Convertir assets para incrustarlos en el ejecutable
# =====================================================================

function(embed_asset TARGET FILE NAME)
  set(out "${CMAKE_BINARY_DIR}/embedded/${NAME}.cpp")
  add_custom_command(
    OUTPUT  "${out}"
    COMMAND ${CMAKE_COMMAND} -DINPUT=${CMAKE_SOURCE_DIR}/${FILE}
            -DOUTPUT=${out} -DNAME=${NAME}
            -P ${CMAKE_SOURCE_DIR}/cmake/embed.cmake
    DEPENDS "${CMAKE_SOURCE_DIR}/${FILE}" ${CMAKE_SOURCE_DIR}/cmake/embed.cmake
    COMMENT "Embedding ${FILE}")
  target_sources(${TARGET} PRIVATE "${out}")
endfunction()

embed_asset(main assets/UnifontExMono.ttf font_unifont)

embed_asset(main assets/gear.png   img_gear)
embed_asset(main assets/folder.png img_folder)
embed_asset(main assets/swap.png   img_swap)
embed_asset(main assets/eye.png    img_eye)
embed_asset(main assets/eyeS.png   img_eyeS)
embed_asset(main assets/dice.png   img_dice)

embed_asset(main assets/languages/en.png img_en)
embed_asset(main assets/languages/zh-Hans.png img_zh_hans)
embed_asset(main assets/languages/es.png img_es)
embed_asset(main assets/languages/fr.png img_fr)
embed_asset(main assets/languages/pt.png img_pt)
embed_asset(main assets/languages/ru.png img_ru)
embed_asset(main assets/languages/id.png img_id)
embed_asset(main assets/languages/de.png img_de)
embed_asset(main assets/languages/ja.png img_ja)
embed_asset(main assets/languages/tr.png img_tr)
embed_asset(main assets/languages/vi.png img_vi)
embed_asset(main assets/languages/fil.png img_fil)
embed_asset(main assets/languages/sw.png img_sw)
embed_asset(main assets/languages/ha.png img_ha)
embed_asset(main assets/languages/ko.png img_ko)
embed_asset(main assets/languages/jv.png img_jv)
embed_asset(main assets/languages/it.png img_it)
embed_asset(main assets/languages/ms.png img_ms)
embed_asset(main assets/languages/am.png img_am)
embed_asset(main assets/languages/yo.png img_yo)
embed_asset(main assets/languages/om.png img_om)
embed_asset(main assets/languages/su.png img_su)
embed_asset(main assets/languages/pl.png img_pl)
embed_asset(main assets/languages/ln.png img_ln)
embed_asset(main assets/languages/uk.png img_uk)
embed_asset(main assets/languages/ff.png img_ff)
embed_asset(main assets/languages/zh-Hant.png img_zh_hant)
embed_asset(main assets/languages/uz.png img_uz)
embed_asset(main assets/languages/ig.png img_ig)
embed_asset(main assets/languages/zu.png img_zu)
embed_asset(main assets/languages/ceb.png img_ceb)
embed_asset(main assets/languages/nl.png img_nl)
embed_asset(main assets/languages/mg.png img_mg)
embed_asset(main assets/languages/ro.png img_ro)
embed_asset(main assets/languages/az.png img_az)
embed_asset(main assets/languages/so.png img_so)
embed_asset(main assets/languages/wo.png img_wo)
embed_asset(main assets/languages/xh.png img_xh)
embed_asset(main assets/languages/af.png img_af)
embed_asset(main assets/languages/kk.png img_kk)
embed_asset(main assets/languages/kmr.png img_kmr)
embed_asset(main assets/languages/rw.png img_rw)
embed_asset(main assets/languages/sn.png img_sn)
embed_asset(main assets/languages/ny.png img_ny)
embed_asset(main assets/languages/el.png img_el)
embed_asset(main assets/languages/hu.png img_hu)
embed_asset(main assets/languages/sv.png img_sv)
embed_asset(main assets/languages/ht.png img_ht)
embed_asset(main assets/languages/cs.png img_cs)
embed_asset(main assets/languages/sr.png img_sr)
embed_asset(main assets/languages/ca.png img_ca)
embed_asset(main assets/languages/ti.png img_ti)
embed_asset(main assets/languages/bg.png img_bg)
embed_asset(main assets/languages/tg.png img_tg)
embed_asset(main assets/languages/qu.png img_qu)
embed_asset(main assets/languages/sq.png img_sq)
embed_asset(main assets/languages/sk.png img_sk)
embed_asset(main assets/languages/tk.png img_tk)
embed_asset(main assets/languages/hy.png img_hy)
embed_asset(main assets/languages/gn.png img_gn)
embed_asset(main assets/languages/hr.png img_hr)
embed_asset(main assets/languages/da.png img_da)
embed_asset(main assets/languages/fi.png img_fi)
embed_asset(main assets/languages/ky.png img_ky)
embed_asset(main assets/languages/nb.png img_nb)
embed_asset(main assets/languages/be.png img_be)
embed_asset(main assets/languages/tt.png img_tt)
embed_asset(main assets/languages/ka.png img_ka)
embed_asset(main assets/languages/mn.png img_mn)
embed_asset(main assets/languages/bs.png img_bs)
embed_asset(main assets/languages/gl.png img_gl)
embed_asset(main assets/languages/lt.png img_lt)
embed_asset(main assets/languages/sl.png img_sl)
embed_asset(main assets/languages/lv.png img_lv)
embed_asset(main assets/languages/mk.png img_mk)
embed_asset(main assets/languages/ga.png img_ga)
embed_asset(main assets/languages/et.png img_et)
embed_asset(main assets/languages/eo.png img_eo)
embed_asset(main assets/languages/eu.png img_eu)
embed_asset(main assets/languages/cy.png img_cy)
embed_asset(main assets/languages/lb.png img_lb)
embed_asset(main assets/languages/mt.png img_mt)
embed_asset(main assets/languages/is.png img_is)
embed_asset(main assets/languages/fo.png img_fo)
