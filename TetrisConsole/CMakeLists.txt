cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Tetris.cpp include/Tetris.h include/Game.h Figure.cpp include/Figure.h Canvas.cpp include/Canvas.h Figure_O.cpp Figure_I.cpp Figure_T.cpp Figure_L.cpp include/Figure_O.h FigureCoordinates.h Point.cpp include/Point.h FigureCoordinates.cpp include/Figure_L.h include/Figure_I.h include/Figure_T.h)
