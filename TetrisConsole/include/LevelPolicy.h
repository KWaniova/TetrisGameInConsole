#ifndef UNTITLED_TETRIS_LEVEL_POLICY_H
#define UNTITLED_TETRIS_LEVEL_POLICY_H

#include "Figures/Figure.h"
#include "Components/Point.h"


class LevelPolicy {
public:
    virtual Figure* pick_random_figure(Point p);
    virtual void print_level_info();
};

Figure* LevelPolicy::pick_random_figure(Point p){};

void LevelPolicy::print_level_info() {
}


#endif //UNTITLED_TETRIS_H
