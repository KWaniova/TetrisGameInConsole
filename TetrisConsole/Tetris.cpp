//
// Created by Krystyna Waniova on 10.01.2023.
//

#include <stack>
#include "include/Tetris.h"
#include "include/Canvas.h"
#include "include/Figure.h"
#include "include/Figure_O.h"
#include "include/Figure_L.h"
#include "include/Figure_T.h"
#include "include/Figure_I.h"

Tetris::Tetris(Canvas _canvas): Game(_canvas) {};


void Tetris::play() {

    // Providing a seed value
    srand((unsigned) time(NULL));

    std::cout << "Tetris game started" << std::endl;
    std::cout << "Preparing figure..." << std::endl;

    COMMAND command;
    while(true){
        command = game_step();
        if(command == COMMAND_QUIT || command == GAME_OVER){
            break;
        }
    }

    show_game_over();
}

void Tetris::show_game_over() {
    std::cout << "==============================="<< std::endl;
    std::cout << "           GAME OVER" << std::endl;
    std::cout << "           SCORE: " << Figure::figure_count << std::endl;
    std::cout << "==============================="<< std::endl;
}


bool Tetris::check_if_game_over() {
    std::cout<<"Checking if game over"<<std::endl;
    auto canvas_array = canvas.get_canvas();
    int width = canvas.get_width();

    for(int i = 0; i < width; i++){
        if(canvas_array[0][i] != canvas.get_empty_char()){
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
    Figure *figure = pick_random_figure();
    bool fall_possible;
    figure->draw(canvas);
    fall_possible = check_figure_fall_possible(figure);
    std::cout << "Fall possible: " << fall_possible << std::endl;
    COMMAND command;
    DIRECTION direction;
    while(fall_possible){
        command = handle_user_command();
        if(command == COMMAND_QUIT)
            return command;
        direction = map_command_to_direction(command);
        figure_fall(figure, direction);
        figure->draw(canvas);
        fall_possible = check_figure_fall_possible(figure);
        std::cout << "Fall possible: " << fall_possible << std::endl;
    }
    draw_figure_on_canvas(figure);
    clear_full_rows();
    canvas.print();
    delete figure;
    if(check_if_game_over()){
        return GAME_OVER;
    };
}

bool check_if_proper_key_pressed(char key){
    key = toupper(key);
    if(key == 'L' || key == 'R' || key == 'D' || key == 'Q'){
        return true;
    }
    return false;
}


COMMAND Tetris::handle_user_command(){
    std::cout << "Pres key: L, R, D or Q to quit game." << std::endl;
    char key = ' ';

    while(check_if_proper_key_pressed(key) == false){
        std::cin >> key;
        key = toupper(key);
        std::cout << "You pressed: " << key << std::endl;
        if(check_if_proper_key_pressed(key) == false){
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

//void Tetris::clear_full_rows() {
//    int height = canvas.get_height();
//    int width = canvas.get_width();
//
//    auto new_canvas = canvas.get_empty_canvas();
//    int new_row = height - 1;
//    for (int row = height - 1; row >= 0; row--) {
//        if (!canvas.is_row_full(row)) {
//            new_canvas[new_row] = canvas.get_canvas()[row];
//            new_row--;
//        }
//    }
//
//    canvas.set_canvas(new_canvas);
//}

void Tetris::clear_full_rows() {
    std::cout << "Clearing full rows" << std::endl;
    auto canvas_array = canvas.get_canvas();

    int height = canvas.get_height();
    int width = canvas.get_width();

    auto new_canvas = canvas.get_empty_canvas();

    int height_idx = height - 1;
    int actualHeight = height_idx;
    while (height_idx >= 0) {
        if (canvas.is_row_full(height_idx)) {
            height_idx--;
        } else {
            new_canvas[actualHeight] = canvas_array[height_idx];
            height_idx--;
            actualHeight--;
        }
    }
    while (actualHeight >= 0) {
        for (int i = 0; i < width; i++) {
            new_canvas[actualHeight][i] = canvas.get_empty_char();
        }
        actualHeight--;
    }
    canvas.set_canvas(new_canvas);
}

Figure* Tetris::pick_random_figure() {
    std::cout<<"Drawing figure"<<std::endl;
    Point position(0, canvas.get_width()/2);

    int random = rand() % 4;
    if(random == 0) {
        return new Figure_O(position);
    } else if(random == 1){
        return new Figure_I(position);
    } else if(random == 2){
        return new Figure_L(position);
    } else if(random == 3){
        return new Figure_T(position);
    }
}


void Tetris::figure_fall(Figure* figure, DIRECTION direction){
    std::cout << "Falling Figure" << std::endl;
    bool move_possible_direction = check_figure_move_possible(figure, direction);
    bool move_possible_down = check_figure_move_possible(figure, DOWN);

    if(move_possible_direction){
        if(direction == LEFT_DOWN){
            figure->move_left();
        }
        else if(direction == RIGHT_DOWN){
            figure->move_right();
        }
    }
    if(move_possible_down) {
        figure->move_down();
    }
}

bool isPointValid(Point point, Canvas canvas){
    if((point.get_x() < 0) || (point.get_y() < 0)){
        return false;
    }
    if( !canvas.is_point_on_canvas(point) ){
        return false;
    }
    return true;
}



bool Tetris::check_figure_move_possible(Figure* figure,DIRECTION direction){
    auto block_coordinates = figure->get_block_coordinates();
    for(auto& coordinates : block_coordinates){
        Point point;
        switch (direction) {
            case LEFT_DOWN:
                point = Point(coordinates.get_x() + 1, coordinates.get_y() - 1);
                break;
            case RIGHT_DOWN:
                point = Point(coordinates.get_x() + 1, coordinates.get_y() + 1);
                break;
            case DOWN:
                point = Point(coordinates.get_x() + 1, coordinates.get_y());
                break;
            default:
                break;
        }
        if (!isPointValid(point, canvas) || !canvas.is_point_empty(point)) {
            return false;
        }
    }
    return true;
}

bool Tetris::check_figure_fall_possible(Figure *figure) {
    std::cout << "Checking fall possible" << std::endl;

    if (check_figure_move_possible(figure ,DOWN)) return true;
    else return false;
}


void Tetris::draw_figure_on_canvas(Figure* figure) {
    canvas.draw_points(figure->get_block_coordinates(), figure->get_color());
}

// TODO:
// zrobic system do wybrania sobie level tetrisa
// (moze byc jeszcze wybór koloru figury po wylosowaniu) (jakis osobny mod z tym dobieraniem?) osobny mod z wyświetlaniem 3 wylosowanych figur i mozna sobie wybać którą się chce