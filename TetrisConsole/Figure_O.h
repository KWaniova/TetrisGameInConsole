//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_FIGURE_O_H
#define UNTITLED_FIGURE_O_H

#include "include/Figure.h"

class Figure_O: public Figure {
public:

    Figure_O();
    ~Figure_O();

    void draw(Canvas);
    void rotate();

    void move_left(Canvas canvas);
    void move_right(Canvas canvas);
    void move_down(Canvas canvas);

};


#endif //UNTITLED_FIGURE_O_H
