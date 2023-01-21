
#include "include/Figure_L.h"
#include "include/Figure.h"
#include "include/Canvas.h"
#include <iostream>

Figure_L::Figure_L(Point position) : Figure( 'L', std::vector<Point>{}) {
    std::cout << "Figure_L created" << std::endl;
    Point point1(position.get_x(), position.get_y());
    Point point2(position.get_x() + 1, position.get_y());
    Point point3(position.get_x() + 1, position.get_y()+1);
    set_block_coordinates(std::vector<Point>{point1, point2, point3});
}

Figure_L::~Figure_L() {
    std::cout << "Figure_L destroyed" << std::endl;
}


