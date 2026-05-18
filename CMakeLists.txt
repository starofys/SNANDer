cmake_minimum_required (VERSION 3.8)
project(SNANDer C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

file(GLOB_RECURSE APP_SOURCES
        src/*.c
)
if(MINGW)
    add_compile_options(-std=gnu99)
endif()
add_compile_definitions(EEPROM_SUPPORT=1)

add_executable(SNANDer ${APP_SOURCES})
target_link_libraries(SNANDer PRIVATE usb-1.0)