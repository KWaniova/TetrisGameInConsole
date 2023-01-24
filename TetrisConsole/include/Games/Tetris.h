//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_TETRIS_H
#define UNTITLED_TETRIS_H

#include <iostream>
#include "../Components/Canvas.h"
#include "../Figures/Figure.h"
#include "../Components/Canvas.h"

enum COMMAND {COMMAND_LEFT, COMMAND_RIGHT, COMMAND_DOWN, COMMAND_QUIT, GAME_OVER};

template <typename TetrisLevelPolicy>
class Tetris {
    TetrisLevelPolicy level_policy;
    Canvas canvas = Canvas();
public:
    Tetris();
    Tetris(Canvas _canvas);
    void play();

    COMMAND game_step();
    COMMAND handle_user_command();
    bool check_if_game_over();
    void clear_full_rows();

    void figure_fall(Figure* figure,  DIRECTION direction);
    void show_game_over();

    void draw_figure_on_canvas(Figure* figure);
    bool check_figure_move_possible(Figure* figure, DIRECTION direction1);
    bool check_figure_fall_possible(Figure* figure);



protected:
    Figure* pick_random_figure();
};



template <typename LevelPolicy>
Tetris<LevelPolicy>::Tetris() {}

template <typename LevelPolicy>
Tetris<LevelPolicy>::Tetris(Canvas _canvas) {
    canvas = _canvas;
};

template <typename LevelPolicy>
void Tetris<LevelPolicy>::play() {

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



template <typename LevelPolicy>
void Tetris<LevelPolicy>::show_game_over() {
    std::cout << "==============================="<< std::endl;
    level_policy.print_level_info();
    std::cout << "       GAME OVER" << std::endl;
    std::cout << "       SCORE: " << Figure::figure_count << std::endl;
    std::cout << "==============================="<< std::endl;
}

template <typename LevelPolicy>
bool Tetris<LevelPolicy>::check_if_game_over() {
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

template <typename LevelPolicy>
COMMAND Tetris<LevelPolicy>::game_step() {
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

template <typename LevelPolicy>
COMMAND Tetris<LevelPolicy>::handle_user_command(){
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

template <class LevelPolicy>
void Tetris<LevelPolicy>::clear_full_rows() {
    int height = canvas.get_height();

    auto new_canvas = canvas.get_empty_canvas();
    int new_row = height - 1;
    for (int row = height - 1; row >= 0; row--) {
        if (!canvas.is_row_full(row)) {
            new_canvas[new_row] = canvas.get_canvas()[row];
            new_row--;
        }
    }

    canvas.set_canvas(new_canvas);
}

template <typename LevelPolicy>
Figure* Tetris<LevelPolicy>::pick_random_figure() {
    std::cout<<"Drawing figure"<<std::endl;
    Point position(0, canvas.get_width()/2);
    return level_policy.pick_random_figure(position);
}

template <typename LevelPolicy>
void Tetris<LevelPolicy>::figure_fall(Figure* figure, DIRECTION direction){
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


template <typename LevelPolicy>
bool Tetris<LevelPolicy>::check_figure_move_possible(Figure* figure,DIRECTION direction){
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

template <typename LevelPolicy>
bool Tetris<LevelPolicy>::check_figure_fall_possible(Figure *figure) {
    std::cout << "Checking fall possible" << std::endl;

    if (check_figure_move_possible(figure ,DOWN)) return true;
    else return false;
}

template <typename LevelPolicy>
void Tetris<LevelPolicy>::draw_figure_on_canvas(Figure* figure) {
    canvas.draw_points(figure->get_block_coordinates(), figure->get_color());
}



#endif //UNTITLED_TETRIS_H
