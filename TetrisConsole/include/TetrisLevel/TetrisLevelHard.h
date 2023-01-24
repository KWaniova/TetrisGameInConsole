//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_TETRIS_LEVEL_HARD_H
#define UNTITLED_TETRIS_LEVEL_HARD_H

#include "../LevelPolicy.h"
#include "../Components/Point.h"
#include "../Figures/Figure_T.h"


class TetrisLevelHard: public LevelPolicy {
public :
    Figure* pick_random_figure(Point p);
void print_level_info();
};

Figure* TetrisLevelHard::pick_random_figure(Point position) {
    // Providing a seed value
    srand((unsigned) time(NULL));

    int random = rand() % 4;
    if(random == 0) {
        return new Figure_O(position);
    } else if(random == 1){
        return new Figure_I(position);
    } else if (random == 2){
        return new Figure_L(position);
    } else{
        return new Figure_T(position);
    }
}

void TetrisLevelHard::print_level_info() {
    std::cout << "Hard level" << std::endl;
}
#endif //UNTITLED_TETRIS_LEVEL_HARD_H
