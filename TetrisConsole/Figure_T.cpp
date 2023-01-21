
#include "include/Figure_T.h"
#include "include/Figure.h"
#include "include/Canvas.h"
#include <iostream>

Figure_T::Figure_T(Point position) : Figure( 'T', std::vector<Point>{}) {
    std::cout << "Figure_T created" << std::endl;
    Point point1(position.get_x(), position.get_y() -1);
    Point point2(position.get_x(), position.get_y() );
    Point point3(position.get_x(), position.get_y() + 1);
    Point point4(position.get_x() + 1, position.get_y() );
    set_block_coordinates(std::vector<Point>{point1, point2, point3, point4});
}

Figure_T::~Figure_T() {
    std::cout << "Figure_T destroyed" << std::endl;
}


