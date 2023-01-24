//
// Created by Krystyna Waniova on 10.01.2023.
//

#include <stack>
#include "include/Battleships.h"
#include "include/Canvas.h"
Battleships::Battleships(Canvas _canvas): Game(_canvas) {};

Battleships::~Battleships() {
    std::cout << "Battleships destroyed" << std::endl;
}

void Battleships::play() {
    std::cout << "Sorry this game is not implemented.. :(" << std::endl;
}