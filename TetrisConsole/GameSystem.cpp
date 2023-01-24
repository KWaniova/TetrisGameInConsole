//
// Created by Krystyna Waniova on 10.01.2023.
//

#include "include/GameSystem.h"
#include "include/Game.h"
#include "include/Games/Battleships.h"
#include "include/Components/Canvas.h"
#include "include/Games/Tetris.h"
#include "include/TetrisLevel/TetrisLevelEasy.h"
#include "include/TetrisLevel/TetrisLevelMedium.h"
#include "include/TetrisLevel/TetrisLevelHard.h"

#include <iostream>

GameSystem::GameSystem() {}

void GameSystem::start() {
    std::cout << "Game started" << std::endl;
    show_menu();
    std::cout << "System is shutting down..." << std::endl;
}


char get_game_level(){
    std::cout << "Chose game level: E(easy), M(Medium), H(Hard)" << std::endl;
    char input;
    while(true){
        std::cin >> input;
        input = toupper(input);

        if(input == 'E' || input =='M' || input =='H'){
            break;
        }
    }
    return input;
}


void play_tetris(){
    char input = get_game_level();
    Canvas c;
    if(input == 'E'){
        Tetris<TetrisLevelEasy> tetris(c);
        tetris.play();
    }
    else if(input == 'M'){
        Tetris<TetrisLevelMedium> tetris(c);
        tetris.play();
    }
    else{
        Tetris<TetrisLevelHard> tetris(c);
        tetris.play();
    }
}

void GameSystem::handle_user_input(USER_INPUT_ENUM input) {
    std::unique_ptr<Game> game;
    switch (input) {
        case GLOBAL_SETTINGS:
            std::cout << "GLOBAL_SETTINGS" << std::endl;
            game_settings();
            break;
        case EXIT:
            std::cout << "Exiting" << std::endl;
            break;
        case WRONG_INPUT:
            std::cout << "Wrong input" << std::endl;
            break;
        case START_TETRIS:
            std::cout << "Starting Tetris" << std::endl;
            play_tetris();
            break;
        case START_BATTLESHIPS:
            std::cout << "Starting Battleships" << std::endl;
            //NOTE: traits
            game = std::make_unique<Battleships>(Canvas());
            game->play();
            break;
    }

}

void GameSystem::show_menu() {
    USER_INPUT_ENUM input;
    while(true){
        std::cout << "============================" << std::endl;
        std::cout << "           Menu" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "1 - Start Tetris game" << std::endl;
        std::cout << "2 - Start Battlefield game" << std::endl;
        std::cout << "S - Settings" << std::endl;
        std::cout << "Q - Exit" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "============================" << std::endl;
        input = take_input();
        if(input == USER_INPUT_ENUM::EXIT){
            break;
        }
        handle_user_input(input);
    }
}

USER_INPUT_ENUM GameSystem::take_input() {
    char input;
    std::cin >> input;
    input = toupper(input);
    switch (input) {
        case '1':
            return START_TETRIS;
        case '2':
            return START_BATTLESHIPS;
        case 'S':
            return GLOBAL_SETTINGS;
        case 'Q':
            return EXIT;
        default:
            return WRONG_INPUT;
    }
}

void GameSystem::game_settings() {
    char c;
    int input;
    char char_input;

    while(c != 'Q'){
        std::cout << "============================" << std::endl;
        std::cout << "        Game settings" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "1 - Change canvas height : "<< Config::get_instance().get_default_canvas_height() << std::endl;
        std::cout << "2 - Change canvas width : "<< Config::get_instance().get_default_canvas_width() << std::endl;
        std::cout << "3 - Change empty symbol : '" << Config::get_instance().get_default_empty_symbol() << '\'' << std::endl;
        std::cout << "4 - Reset to default settings '" << Config::get_instance().get_default_empty_symbol() << '\'' << std::endl;
        std::cout << "Q - Exit" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "============================" << std::endl;
        std::cin >> c;
        c = toupper(c);
        switch(c){
            case '1':
                std::cout << "Enter new canvas height" << std::endl;
                std::cin >> input;
                Config::get_instance().set_default_canvas_height(input);
                break;
            case '2':
                std::cout << "Enter new canvas width" << std::endl;
                std::cin >> input;
                Config::get_instance().set_default_canvas_width(input);
                break;
            case '3':
                std::cout << "Enter new empty symbol" << std::endl;
                std::cin >> char_input;
                Config::get_instance().set_default_empty_symbol(char_input);
                break;

             case '4':
                std::cout << "Resetting to default state" << std::endl;
                Config::get_instance().reset_config_state();
                break;
            case 'Q':
                std::cout << "Exiting" << std::endl;
                break;
            default:
                std::cout << "Wrong input" << std::endl;
        }
    }

}

