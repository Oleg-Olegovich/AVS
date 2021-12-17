cmake_minimum_required(VERSION 3.20)
project(AvsLab3 C ASM_NASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp -F dwarf")
SET(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -no-pie")

include_directories(source)

add_executable(AvsLab3
        source/matrix.h
        source/generator.h
        source/reader.h
        source/container.h
        source/generator.c
        source/matrix.c
        source/reader.c
        source/main.c)