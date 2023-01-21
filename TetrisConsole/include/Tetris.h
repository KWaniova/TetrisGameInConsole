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

    COMMAND game_step();
    COMMAND handle_user_command();
    bool check_if_game_over();
    void clear_full_rows();

    void figure_fall(Figure* figure,  DIRECTION direction);
    void show_game_over();

    void draw_figure_on_canvas(Figure* figure);
    bool check_figure_move_possible(Figure* figure, DIRECTION direction1);
    bool check_figure_fall_possible(Figure* figure);

    Figure* pick_random_figure();
};


#endif //UNTITLED_TETRIS_H
