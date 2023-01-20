//
// Created by Krystyna Waniova on 10.01.2023.
//

#include "FigureCoordinates.h"
#include <iostream>

FigureCoordinates::FigureCoordinates() {
}

FigureCoordinates::FigureCoordinates(Point _point1, Point _point2, Point _point3, Point _point4) {
    point1 = _point1;
    point2 = _point2;
    point3 = _point3;
    point4 = _point4;
}

FigureCoordinates::~FigureCoordinates() {
}

void FigureCoordinates::set_point1(Point _point) {
    point1 = _point;
}

void FigureCoordinates::set_point2(Point _point) {
    point2 = _point;
}

void FigureCoordinates::set_point3(Point _point) {
    point3 = _point;
}

void FigureCoordinates::set_point4(Point _point) {
    point4 = _point;
}


Point FigureCoordinates::get_point1() {
    return point1;
}

Point FigureCoordinates::get_point2() {
    return point2;
}

Point FigureCoordinates::get_point3() {
    return point3;
}

Point FigureCoordinates::get_point4() {
    return point4;
}


void FigureCoordinates::print() {
    std::cout << "Point 1: " << std::endl;
    point1.print();
    std::cout << "Point 2: " << std::endl;
    point2.print();
    std::cout << "Point 3: " << std::endl;
    point3.print();
    std::cout << "Point 4: " << std::endl;
    point4.print();
}