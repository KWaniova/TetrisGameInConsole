//
// Created by Krystyna Waniova on 10.01.2023.
//

#include <iostream>
#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#include "Components/Canvas.h"

class Game {
protected:
    Canvas canvas;
public:
    Game(Canvas _canvas);
    ~Game();
    virtual void play();
};

Game::Game(Canvas _canvas): canvas(_canvas) {};

Game::~Game() {
    std::cout << "Game destroyed" << std::endl;
}
void Game::play() {}
#endif //UNTITLED_GAME_H
