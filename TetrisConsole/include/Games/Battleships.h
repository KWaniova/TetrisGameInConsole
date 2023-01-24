//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_BATTLESHIPS_H
#define UNTITLED_BATTLESHIPS_H

#include <iostream>
#include "../Components/Canvas.h"
#include "../Game.h"

class Battleships: public Game{
public:
    Battleships(Canvas _canvas);
    ~Battleships();
    void play();
};
Battleships::Battleships(Canvas _canvas): Game(_canvas){};

Battleships::~Battleships() {
    std::cout << "Battleships destroyed" << std::endl;
}

void Battleships::play() {
    std::cout << "Sorry this game is not implemented.. :(" << std::endl;
}


#endif //UNTITLED_BATTLESHIPS_H
