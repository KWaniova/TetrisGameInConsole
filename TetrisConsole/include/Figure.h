//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef TETRIMINO_H
#define TETRIMINO_H


#include "../FigureCoordinates.h"
#include "Canvas.h"

class Figure {
    int ID;
    static int figure_count;

public:
    char color;
    FigureCoordinates coordinates;
    Figure();
    Figure(FigureCoordinates _coordinates);
    ~Figure();
    virtual void draw(Canvas canvas);
    virtual void move_left(Canvas canvas);
    virtual void move_right(Canvas canvas);
    virtual void move_down(Canvas canvas);
    void print_coordinates();
};



#endif


//narazie 3 kształty 0 -