cmake_minimum_required(VERSION 3.21)
project(bigDecimmallnt)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bigDecimmallnt
        bigDecimmallnt.h
        functions.cpp
        main.cpp)
