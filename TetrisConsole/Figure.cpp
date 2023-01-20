//
// Created by Krystyna Waniova on 10.01.2023.
//

#include "include/Figure.h"
#include <iostream>

int Figure::figure_count = 0;

Figure::Figure() {
    std::cout << "Figure created" << std::endl;
    ID = figure_count;
    figure_count++;
}

Figure::Figure(FigureCoordinates _coordinates) {
    ID = figure_count;
    figure_count++;
    coordinates = _coordinates;
    std::cout << "Figure created of id: "<< ID << std::endl;
}

Figure::~Figure() {
    std::cout << "Figure destroyed" << std::endl;
}

void Figure::draw(Canvas canvas) {
    std::cout << "Drawing Figure" << std::endl;
}

void Figure::move_left(Canvas canvas) {
    std::cout << "Moving Figure left" << std::endl;
    coordinates.set_point1(Point(coordinates.get_point1().get_x() -1, coordinates.get_point1().get_y() ));
    coordinates.set_point2(Point(coordinates.get_point2().get_x() -1, coordinates.get_point2().get_y()));
    coordinates.set_point3(Point(coordinates.get_point3().get_x()- 1, coordinates.get_point3().get_y()));
    coordinates.set_point4(Point(coordinates.get_point4().get_x() -1, coordinates.get_point4().get_y() ));
}

void Figure::move_right(Canvas canvas) {
    std::cout << "Moving Figure right" << std::endl;

    coordinates.set_point1(Point(coordinates.get_point1().get_x(), coordinates.get_point1().get_y() + 1));
    coordinates.set_point2(Point(coordinates.get_point2().get_x(), coordinates.get_point2().get_y() + 1));
    coordinates.set_point3(Point(coordinates.get_point3().get_x(), coordinates.get_point3().get_y() + 1));
    coordinates.set_point4(Point(coordinates.get_point4().get_x(), coordinates.get_point4().get_y() + 1));
}

void Figure::move_down(Canvas canvas) {
    std::cout << "Moving Figure down" << std::endl;
    coordinates.set_point1(Point(coordinates.get_point1().get_x() + 1, coordinates.get_point1().get_y()));
    coordinates.set_point2(Point(coordinates.get_point2().get_x() + 1, coordinates.get_point2().get_y()));
    coordinates.set_point3(Point(coordinates.get_point3().get_x() + 1, coordinates.get_point3().get_y()));
    coordinates.set_point4(Point(coordinates.get_point4().get_x() + 1, coordinates.get_point4().get_y()));
}

void Figure::print_coordinates() {
    std::cout << "Figure coordinates: " << std::endl;
    coordinates.print();
}


