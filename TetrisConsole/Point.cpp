//
// Created by Krystyna Waniova on 10.01.2023.
//

#include "include/Point.h"
#include <iostream>

Point::Point() {
}

Point::Point(int _x, int _y) {
    x = _x;
    y = _y;
}

int Point::get_x() {
    return x;
}


int Point::get_y() {
    return y;
}

void Point::set_x(int _x) {
    x = _x;
}

void Point::set_y(int _y) {
    y = _y;
}

void Point::print() {
    std::cout << "x: " << x << " y: " << y << std::endl;
}

