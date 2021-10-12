cmake_minimum_required(VERSION 3.20)
project(AvsLab0 C)

set(CMAKE_C_STANDARD 99)

include_directories(source)

add_executable(AvsLab0
        source/basic_matrix.c
        source/basic_matrix.h
        source/diagonal_matrix.c
        source/diagonal_matrix.h
        source/in_out_functions.c
        source/in_out_functions.h
        source/main.c
        source/sort.c
        source/sort.h
        source/triangular_matrix.c
        source/triangular_matrix.h
        source/usual_matrix.c
        source/usual_matrix.h source/usual_matrix.c)
