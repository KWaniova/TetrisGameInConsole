
#include "include/Figure_I.h"
#include "include/Figure.h"
#include "include/Canvas.h"
#include <iostream>

Figure_I::Figure_I(Point position) : Figure('i', std::vector<Point>{}) {
    std::cout << "Figure_I created" << std::endl;
    Point point1(position.get_x(), position.get_y() );
    Point point2(position.get_x() + 1, position.get_y()  );
    Point point3(position.get_x() + 2, position.get_y() );
    Point point4(position.get_x() + 3, position.get_y()  );
    set_block_coordinates(std::vector<Point>{point1, point2, point3, point4});
}

Figure_I::~Figure_I() {
    std::cout << "Figure_I destroyed" << std::endl;
}


