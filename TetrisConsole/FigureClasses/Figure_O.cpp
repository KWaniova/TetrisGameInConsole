
#include "../include/Figures/Figure_O.h"
#include "../include/Figures/Figure.h"
#include "../include/Components/Canvas.h"
#include <iostream>

Figure_O::Figure_O(Point position) : Figure('O', std::vector<Point>{}) {
    std::cout << "Figure_O created" << std::endl;
    Point point1(position.get_x(), position.get_y() );
    Point point2(position.get_x(), position.get_y()  + 1);
    Point point3(position.get_x() + 1, position.get_y() );
    Point point4( position.get_x() + 1, position.get_y()  + 1);
    set_block_coordinates(std::vector<Point>{point1, point2, point3, point4});
}

Figure_O::~Figure_O() {
    std::cout << "Figure_O destroyed" << std::endl;
}


