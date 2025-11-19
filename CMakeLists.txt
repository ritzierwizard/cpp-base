cmake_minimum_required(VERSION 4.0)
project(base)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/core)

add_executable(base
        include/core/string.h
        main.cpp
        include/core/array.h)
