//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_TETRIS_LEVEL_MEDIUM_H
#define UNTITLED_TETRIS_LEVEL_MEDIUM_H

#include "../LevelPolicy.h"
#include "../Components/Point.h"
#include "../Figures/Figure_L.h"


class TetrisLevelMedium: public LevelPolicy {
public :
    Figure* pick_random_figure(Point p);
    void print_level_info();
};


Figure* TetrisLevelMedium::pick_random_figure(Point position) {
    // Providing a seed value
    srand((unsigned) time(NULL));

    int random = rand() % 3;
    if(random == 0) {
        return new Figure_O(position);
    } else if(random == 1){
        return new Figure_I(position);
    } else {
        return new Figure_L(position);
    }
}

void TetrisLevelMedium::print_level_info() {
    std::cout << "Medium level" << std::endl;
}

#endif //UNTITLED_TETRIS_LEVEL_MEDIUM_H
