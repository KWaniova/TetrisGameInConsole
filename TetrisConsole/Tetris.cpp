//
// Created by Krystyna Waniova on 10.01.2023.
//

#include <stack>
#include "include/Tetris.h"
#include "include/Canvas.h"
#include "include/Figure.h"
#include "Figure_O.h"

Tetris::Tetris(Canvas _canvas){
    canvas = _canvas;
};


void Tetris::play() {

    // Providing a seed value
    srand((unsigned) time(NULL));

    std::cout << "Tetris game started" << std::endl;
    std::cout << "Preparing figure..." << std::endl;

    COMMAND command;
    for(int i = 0; i < 10; i++){
        command = game_step();
        if(command == COMMAND_QUIT || command == GAME_OVER){
            break;
        }
    }

    std::cout << "Tetris game ended" << std::endl;
    std::cout << "Game over" << std::endl;

    std::cout << "SCORE " << Figure::figure_count << std::endl;

}

void Tetris::clear_full_rows() {
    std::cout<<"Clearing full rows"<<std::endl;
    char** canvas_array = canvas.get_canvas();

    int height = canvas.get_height();
    int width = canvas.get_width();

    char ** canvasCopy = new char *[height];
    for (int row = 0; row < height; row++)
        canvasCopy[row] = new char[width];

    int height_idx = height -1;
    int actualHeight = height_idx;
    while(height_idx >= 0){
         if(canvas.is_row_full(height_idx)){
             height_idx--;
         } else {
             canvasCopy[actualHeight] = canvas_array[height_idx];
             height_idx--;
             actualHeight--;
         }
    }
    while(actualHeight >=0){
        for(int i = 0; i < width; i++){
            canvasCopy[actualHeight][i] = ' ';
        }
        actualHeight--;
    }
    canvas.set_canvas(canvasCopy);
}

bool Tetris::check_if_game_over() {
    std::cout<<"Checking if game over"<<std::endl;
    char** canvas_array = canvas.get_canvas();
    int width = canvas.get_width();

    for(int i = 0; i < width; i++){
        if(canvas_array[0][i] != ' '){
            return true;
        }
    }
    return false;
}

DIRECTION map_command_to_direction(COMMAND command){
    if(command == COMMAND_LEFT){
        return LEFT_DOWN;
    }
    else if(command == COMMAND_RIGHT){
        return RIGHT_DOWN;
    }
    else if(command == COMMAND_DOWN){
        return DOWN;
    }
}


COMMAND Tetris::game_step() {
    Figure *figure = new Figure_O(canvas);
    bool fall_possible;
    figure->print_coordinates();
    figure->draw(canvas);
    fall_possible = figure->check_fall_possible();
    std::cout << "Fall possible: " << fall_possible << std::endl;
    COMMAND command;
    DIRECTION direction;
    while(fall_possible){
        command = handle_user_command();
        if(command == COMMAND_QUIT)
            return command;
        direction = map_command_to_direction(command);
        figure->fall(direction);
        figure->draw(canvas);
        fall_possible = figure->check_fall_possible();
        std::cout << "Fall possible: " << fall_possible << std::endl;
    }
    figure->draw_on_canvas();
    clear_full_rows();
    canvas.draw();
    if(check_if_game_over()){
        return GAME_OVER;
    };
}


COMMAND Tetris::handle_user_command(){
    std::cout << "Pres key: L, R or D." << std::endl;
    char key = ' ';

    while( key != 'L' && key != 'R' && key != 'D'){
        std::cin >> key;
        key = toupper(key);
        std::cout << "You pressed: " << key << std::endl;
        if( key != 'L' && key != 'R' && key != 'D'){
            std::cout << "Wrong key pressed. Try again" << std::endl;
        }
    }
    if(key == 'L'){
        return COMMAND_LEFT;
    } else if(key == 'R'){
        return COMMAND_RIGHT;
    } else if(key == 'D'){
        return COMMAND_DOWN;
    }
    return COMMAND_QUIT;
}





/*
 *
void Tetris::play() {

    // Providing a seed value
    srand((unsigned) time(NULL));

    std::cout << "Tetris game started" << std::endl;
    std::cout << "Preparing figure..." << std::endl;
    for(int i = 0; i < 10; i++){
        Figure *figure = new Figure_O(canvas);
        bool fall_possible = true;
        figure->print_coordinates();
        figure->draw(canvas);
        fall_possible = figure->check_fall_possible();
        std::cout << "Fall possible: " << fall_possible << std::endl;
        DIRECTION direction;
        while(fall_possible){
            direction = game_step();
//            int random = rand() % 3;
//
//            if(random == 0){
//                direction = DOWN;
//            } else if(random == 1){
//                direction = RIGHT_DOWN;
//            } else {
//                direction = LEFT_DOWN;
//            }

            figure->fall(direction);
            figure->draw(canvas);

            fall_possible = figure->check_fall_possible();
            std::cout << "Fall possible: " << fall_possible << std::endl;
        }
        figure->draw_on_canvas();
        canvas.draw();
        clear_full_rows();
        canvas.draw();

    }

}
 */