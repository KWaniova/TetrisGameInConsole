//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_BATTLESHIPS_H
#define UNTITLED_BATTLESHIPS_H

#include <iostream>
#include "Canvas.h"
#include "Game.h"

class Battleships: public Game{
public:
    Battleships(Canvas _canvas);
    ~Battleships();
    void play();
};


#endif //UNTITLED_BATTLESHIPS_H
