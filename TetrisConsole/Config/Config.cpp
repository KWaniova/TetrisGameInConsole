//
// Created by Krystyna Waniova on 10.01.2023.
//

//NOTE: Singleton
#include "../include/Config.h"
Config::Config(){};

int Config::get_default_canvas_height() {
    return CANVAS_HEIGHT;
}

int Config::get_default_canvas_width() {
    return CANVAS_WIDTH;
}

char Config::get_default_empty_symbol() {
    return EMPTY_SYMBOL;
}

void Config::set_default_canvas_height(int height) {
    CANVAS_HEIGHT = height;
}

void Config::set_default_canvas_width(int width) {
    CANVAS_WIDTH = width;
}

void Config::set_default_empty_symbol(char empty_symbol) {
    EMPTY_SYMBOL = empty_symbol;
}

void Config::reset_config_state() {
    CANVAS_HEIGHT = DEFAULT_CANVAS_HEIGHT;
    CANVAS_WIDTH = DEFAULT_CANVAS_HEIGHT;
    EMPTY_SYMBOL = DEFAULT_EMPTY_SYMBOL;
}


