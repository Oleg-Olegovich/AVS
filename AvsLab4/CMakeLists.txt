cmake_minimum_required(VERSION 3.16)
project(AvsLab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(AvsLab4
        source/main.cpp
        source/garden.cpp
        source/garden.h
        source/gardener.cpp
        source/gardener.h
        source/modes.h)
