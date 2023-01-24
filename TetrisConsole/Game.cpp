//
// Created by Krystyna Waniova on 10.01.2023.
//

#include "include/Game.h"
#include <iostream>

Game::Game(Canvas _canvas) {
    std::cout << "Game created" << std::endl;
    canvas = _canvas;
}

Game::~Game() {
    std::cout << "Game destroyed" << std::endl;
}

void Game::play() {}