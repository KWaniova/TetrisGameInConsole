//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_TETRIS_H
#define UNTITLED_TETRIS_H

#include <iostream>
#include "Canvas.h"
#include "Figure.h"

enum COMMAND {COMMAND_LEFT, COMMAND_RIGHT, COMMAND_DOWN, COMMAND_QUIT, GAME_OVER};

class Tetris{
    Canvas canvas = Canvas(0, 0, 0);
public:
    Tetris(Canvas _canvas);
    void play();

    void clear_full_rows();

    COMMAND game_step();
    COMMAND handle_user_command();
    bool check_if_game_over();

    void show_game_over();
};


#endif //UNTITLED_TETRIS_H
