cmake_minimum_required(VERSION 3.13)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Tetris
        src/Tetris.cpp
        main.cpp)
