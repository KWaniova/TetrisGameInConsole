//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#include "Canvas.h"

class Game {
protected:
    Canvas canvas;
public:
    Game(Canvas _canvas);
    ~Game();
    virtual void play();
};


#endif //UNTITLED_GAME_H
