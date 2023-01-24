
#ifndef UNTITLED_GAME_SYSTEM_H
#define UNTITLED_GAME_SYSTEM_H

#include "Canvas.h"
#include "Config.h"

enum USER_INPUT_ENUM {
    START_TETRIS ,
    START_BATTLESHIPS ,
    GLOBAL_SETTINGS,
    EXIT ,
    WRONG_INPUT ,
};

class GameSystem {
    void show_menu();
    void game_settings();
    void handle_games(USER_INPUT_ENUM input);
    USER_INPUT_ENUM take_input();
    void handle_user_input(USER_INPUT_ENUM input);
public:
    GameSystem();
    void start();

};


#endif //UNTITLED_GAME_SYSTEM_H
