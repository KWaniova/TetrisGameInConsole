cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        include/Games/Tetris.h
        include/Games/Battleships.h
        include/Game.h
        include/GameSystem.h
        FigureClasses/Figure.cpp
        include/Figures/Figure.h
        Canvas.cpp
        include/Components/Canvas.h
        FigureClasses/Figure_O.cpp
        FigureClasses/Figure_I.cpp
        FigureClasses/Figure_T.cpp
        FigureClasses/Figure_L.cpp include/Figures/Figure_O.h
        include/Components/FigureCoordinates.h Point.cpp include/Components/Point.h
        FigureCoordinates.cpp include/Figures/Figure_L.h include/Figures/Figure_I.h
        include/Figures/Figure_T.h GameSystem.cpp Config/Config.cpp
        include/Config.h
        include/LevelPolicy.h
        include/TetrisLevel/TetrisLevelMedium.h
        include/TetrisLevel/TetrisLevelHard.h
        include/TetrisLevel/TetrisLevelEasy.h
        )
