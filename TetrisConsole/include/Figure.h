//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef FIGURE_H
#define FIGURE_H


#include <vector>
#include "Canvas.h"


enum DIRECTION {LEFT_DOWN, RIGHT_DOWN, DOWN};

class Figure{
    using point_type = Canvas::public_point_type;
    point_type color;
    using figure_type = std::vector<Point>;

    int ID;
    figure_type block_coordinates;

public:
    static int figure_count;

    void move_left();
    void move_right();
    void move_down();
    Figure(point_type _color, figure_type _coordinates);
    ~Figure();
    void draw(Canvas canvas);
    void print_coordinates();
    figure_type get_block_coordinates();
    point_type get_color();
    void set_block_coordinates(figure_type _coordinates);
};



#endif
