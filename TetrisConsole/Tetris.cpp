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

Tetris::Tetris(Canvas _canvas){
    canvas = _canvas;
};


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
    std::cout << "Checking move possible " << direction << std::endl;
    auto block_coordinates = figure->get_block_coordinates();
    switch (direction)
    {
        case LEFT_DOWN:
            for(int i = 0; i < block_coordinates.size(); i++){
                Point point(block_coordinates[i].get_x() +1, block_coordinates[i].get_y() - 1);
                if(!isPointValid(point, canvas) || !canvas.is_point_empty(point)) {
                    return false;
                };
            };
            break;
        case RIGHT_DOWN:
            for(int i = 0; i < block_coordinates.size(); i++){
                Point point(block_coordinates[i].get_x() + 1, block_coordinates[i].get_y() + 1);
                if(!isPointValid(point, canvas) || !canvas.is_point_empty(point)) {
                    return false;
                };
            };
            break;
        case DOWN:
            for(int i = 0; i < block_coordinates.size(); i++){
                Point point(block_coordinates[i].get_x() + 1, block_coordinates[i].get_y());
                if(!isPointValid(point, canvas) || !canvas.is_point_empty(point)) {
                    return false;
                };
            };
            break;
        default:
            break;
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
