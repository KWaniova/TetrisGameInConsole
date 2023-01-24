//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_TETRIS_LEVEL_EASY_H
#define UNTITLED_TETRIS_LEVEL_EASY_H

#include "../Components/Point.h"
#include "../Figures/Figure.h"
#include "../Figures/Figure_O.h"
#include "../Figures/Figure_I.h"
#include "../LevelPolicy.h"


class TetrisLevelEasy: public LevelPolicy {

public :
    Figure* pick_random_figure(Point p);
void print_level_info();
};



Figure* TetrisLevelEasy::pick_random_figure(Point position) {
    // Providing a seed value
    srand((unsigned) time(NULL));

    int random = rand() % 2;
    if(random == 0) {
        return new Figure_O(position);
    } else {
        return new Figure_I(position);
    }
}

void TetrisLevelEasy::print_level_info() {
    std::cout << "Easy level" << std::endl;
}


#endif //UNTITLED_TETRIS_LEVEL_EASY_H
