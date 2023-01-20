
#include "Figure_O.h"
#include "include/Canvas.h"
#include <iostream>

Figure_O::Figure_O() {
    FigureCoordinates _coordinates = FigureCoordinates(Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1));
    coordinates = _coordinates;
    std::cout << "Figure_O created" << std::endl;
    color = 'o';
}

Figure_O::~Figure_O() {
    std::cout << "Figure_O destroyed" << std::endl;
}

void Figure_O::draw(Canvas canvas) {
    std::cout << "Drawing Figure_O" << std::endl;

    char** canvas_array = canvas.get_canvas();
    canvas_array[coordinates.get_point1().get_x()][coordinates.get_point1().get_y()] = color;
    canvas_array[coordinates.get_point2().get_x()][coordinates.get_point2().get_y()] = color;
    canvas_array[coordinates.get_point3().get_x()][coordinates.get_point3().get_y()] = color;
    canvas_array[coordinates.get_point4().get_x()][coordinates.get_point4().get_y()] = color;

    canvas.print_canvas_edge();
    for (int row = 0; row < canvas.get_height(); row++)
    {
        for (int col = 0; col < canvas.get_width(); col++)
            std::cout << canvas_array[row][col] << " ";
        std::cout << std::endl;
    };
    canvas.print_canvas_edge();
}


void Figure_O::rotate() {
    std::cout << "Rotating Figure_O" << std::endl;
}


void Figure_O::move_left(Canvas canvas) {
    std::cout << "Moving Figure_O left" << std::endl;
    //TODO: check if move is possible for this figure on canvas

    Figure::move_left(canvas);
}

void Figure_O::move_down(Canvas canvas) {
    std::cout << "Moving Figure_O down" << std::endl;
    //TODO: check if move is possible for this figure on canvas
    Figure::move_down(canvas);
}

void Figure_O::move_right(Canvas canvas) {
    std::cout << "Moving Figure_O right" << std::endl;
    //TODO: check if move is possible for this figure on canvas
    Figure::move_right(canvas);
}