//
// Created by Krystyna Waniova on 10.01.2023.
//

#include "include/Figure.h"
#include <iostream>

int Figure::figure_count = 0;

Figure::Figure(Canvas _canvas, char _color, std::vector<Point> _coordinates) : canvas(_canvas) {
    ID = figure_count;
    figure_count++;
    color = _color;
    block_coordinates = _coordinates;
    std::cout << "Figure created of id: "<< ID << std::endl;
}

Figure::~Figure() {
    std::cout << "Figure destroyed" << std::endl;
}

std::vector<Point> Figure::get_coordinates() {
    return block_coordinates;
}

void Figure::draw(Canvas canvas) {
    std::cout << "Drawing Figure" << std::endl;

    char** canvas_array = canvas.get_canvas();

    canvas_array[block_coordinates[0].get_x()][block_coordinates[0].get_y()] = color;
    canvas_array[block_coordinates[1].get_x()][block_coordinates[1].get_y()] = color;
    canvas_array[block_coordinates[2].get_x()][block_coordinates[2].get_y()] = color;
    canvas_array[block_coordinates[3].get_x()][block_coordinates[3].get_y()] = color;

    canvas.print_canvas_edge();

    for (int row = 0; row < canvas.get_height(); row++)
    {
        for (int col = 0; col < canvas.get_width(); col++)
            std::cout << canvas_array[row][col] << " ";
        std::cout << std::endl;
    };
    canvas.print_canvas_edge();
}

char Figure::get_color() {
    return color;
}

void Figure::move_left() {
    std::cout << "Moving Figure left" << std::endl;
    for(int i = 0; i < block_coordinates.size(); i++){
        block_coordinates[i].set_y(block_coordinates[i].get_y() -1);
    }
}

void Figure::move_right() {
    std::cout << "Moving Figure right" << std::endl;
    for(int i = 0; i < block_coordinates.size(); i++){
        block_coordinates[i].set_y(block_coordinates[i].get_y() + 1);
    }
}

void Figure::fall(DIRECTION direction){
    std::cout << "Falling Figure" << std::endl;
    bool move_possible_direction = check_move_possible(direction);
    bool move_possible_down = check_move_possible(DOWN);

    if(move_possible_direction){
        if(direction == LEFT_DOWN){
            move_left();
        }
        else if(direction == RIGHT_DOWN){
            move_right();
        }
    }
    if(move_possible_down) {
        move_down();
    }
}


void Figure::move_down() {
    std::cout << "Moving Figure down" << std::endl;
    for(int i = 0; i < block_coordinates.size(); i++){
        block_coordinates[i].set_x(block_coordinates[i].get_x()+1);
    }
}

void Figure::print_coordinates() {
    std::cout << "Figure coordinates: " << std::endl;
    for(int i = 0; i < block_coordinates.size(); i++){
        block_coordinates[i].print();
    }
}

void Figure::set_block_coordinates(std::vector<Point> _coordinates) {
    std::cout << "Setting Figure coordinates" << std::endl;
    block_coordinates = _coordinates;
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

bool Figure::check_move_possible(DIRECTION direction){
    std::cout << "Checking move possible " << direction << std::endl;

    switch (direction)
    {
        case LEFT_DOWN:
//            std::cout << "Checking move possible left" << std::endl;
            for(int i = 0; i < block_coordinates.size(); i++){
                Point point(block_coordinates[i].get_x() +1, block_coordinates[i].get_y() - 1);
                if(!isPointValid(point, canvas) || !canvas.is_point_empty(point)) {
                    return false;
                };
            };
            break;
        case RIGHT_DOWN:
//            std::cout << "Checking move possible right" << std::endl;
            for(int i = 0; i < block_coordinates.size(); i++){
                Point point(block_coordinates[i].get_x() + 1, block_coordinates[i].get_y() + 1);
                if(!isPointValid(point, canvas) || !canvas.is_point_empty(point)) {
                    return false;
                };
            };
            break;
        case DOWN:
//            std::cout << "Checking move possible down" << std::endl;
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

bool Figure::check_fall_possible() {
    std::cout << "Checking fall possible" << std::endl;

    if (check_move_possible(DOWN)) return true;
    else return false;
}


void Figure::draw_on_canvas() {
//    std::cout << "Drawing Figure on canvas" << std::endl;
    canvas.draw_points(this->block_coordinates, this->color);
}
