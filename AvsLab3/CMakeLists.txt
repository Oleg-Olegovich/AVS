cmake_minimum_required(VERSION 3.20)
project(AvsLab3 C ASM_NASM)

set(CMAKE_C_STANDARD 11)
set(
        PROJECT_HEADERS
        source/matrix/matrix.h source/generator/generator.h source/container/container.h
        source/reader/reader.h)
set(
        PROJECT_SOURCES
        source/main.c source/generator/generator.c source/matrix/matrix.c source/container/container.asm
        source/reader/reader.c)

set(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp -F dwarf")
SET(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -no-pie")

add_executable(AvsLab3 ${PROJECT_SOURCES} ${PROJECT_HEADERS})