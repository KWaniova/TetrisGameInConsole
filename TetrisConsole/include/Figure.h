//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef TETRIMINO_H
#define TETRIMINO_H


#include <vector>
#include "../FigureCoordinates.h"
#include "Canvas.h"

enum DIRECTION {LEFT_DOWN, RIGHT_DOWN, DOWN};

//TODO: here can be RFC
class Figure {
    int ID;
    std::vector<Point> block_coordinates;
    Canvas canvas;
    char color;

    void move_left();
    void move_right();
    void move_down();

public:
    static int figure_count;
    Figure(Canvas _canvas, char _color, std::vector<Point> _coordinates);
    ~Figure();
    void draw(Canvas canvas);
    void fall(DIRECTION direction);
    void print_coordinates();
    std::vector<Point> get_coordinates();
    Canvas get_canvas();
    char get_color();
    void draw_on_canvas();
    bool check_move_possible(DIRECTION direction);
    bool check_fall_possible();
    void set_block_coordinates(std::vector<Point> _coordinates);

};



#endif


//narazie 3 kształty 0 -