cmake_minimum_required(VERSION 3.16.3)
project(AvsLab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AvsLab1
        source/main.cpp
        source/basic_matrix.cpp
        source/basic_matrix.h
        source/diagonal_matrix.cpp
        source/diagonal_matrix.h
        source/triangular_matrix.cpp
        source/triangular_matrix.h
        source/usual_matrix.cpp
        source/usual_matrix.h
        source/error_handler.cpp
        source/error_handler.h)
