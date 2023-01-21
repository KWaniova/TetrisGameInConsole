//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_TETRIS_H
#define UNTITLED_TETRIS_H

#include <iostream>
#include "Canvas.h"

class Tetris{
    Canvas canvas = Canvas(0, 0, 0);
public:
    Tetris(Canvas _canvas);
    void play();

    void clear_full_rows();
};


#endif //UNTITLED_TETRIS_H
