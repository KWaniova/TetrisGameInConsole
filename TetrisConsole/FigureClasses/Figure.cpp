//
// Created by Krystyna Waniova on 10.01.2023.
//

#include "../include/Figures/Figure.h"
#include <iostream>

int Figure::figure_count = 0;

Figure::Figure(point_type _color, figure_type _coordinates) : color(_color), block_coordinates(_coordinates) {
    ID = figure_count;
    figure_count++;
    std::cout << "Figure created - id: "<< ID << std::endl;
}

Figure::~Figure() {
    std::cout << "Figure destroyed" << std::endl;
}

Figure::figure_type Figure::get_block_coordinates() {
    return block_coordinates;
}

void Figure::draw(Canvas canvas) {
    std::cout << "Drawing Figure" << std::endl;
    auto canvas_array = canvas.get_canvas();
    for (int i = 0; i < block_coordinates.size(); i++) {
        Point point = block_coordinates[i];
        canvas_array[point.get_x()][point.get_y()] = color;
    }

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

void Figure::set_block_coordinates(figure_type _coordinates) {
    std::cout << "Setting Figure coordinates" << std::endl;
    block_coordinates = _coordinates;
}

