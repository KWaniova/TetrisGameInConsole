//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef FIGURE_H
#define FIGURE_H


#include <vector>
#include "Canvas.h"


enum DIRECTION {LEFT_DOWN, RIGHT_DOWN, DOWN};

class Figure{
    using color_type = char;

    int ID;
    std::vector<Point> block_coordinates;
    color_type color;

public:
    static int figure_count;

    void move_left();
    void move_right();
    void move_down();
    Figure(char _color, std::vector<Point> _coordinates);
    ~Figure();
    void draw(Canvas canvas);
    void print_coordinates();
    std::vector<Point> get_block_coordinates();
    char get_color();

    void set_block_coordinates(std::vector<Point> _coordinates);

};



#endif
