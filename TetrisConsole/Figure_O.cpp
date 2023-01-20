
#include "Figure_O.h"
#include "include/Figure.h"
#include "include/Canvas.h"
#include <iostream>

Figure_O::Figure_O(Canvas canvas) : Figure(canvas, 'O', std::vector<Point>{}) {
    std::cout << "Figure_O created" << std::endl;
    int canvas_center_width = (canvas.get_width() - 1) / 2;
    Point point1(0, canvas_center_width );
    Point point2(0, canvas_center_width  + 1);
    Point point3(1, canvas_center_width );
    Point point4(1, canvas_center_width  + 1);
    set_block_coordinates(std::vector<Point>{point1, point2, point3, point4});
}

Figure_O::~Figure_O() {
    std::cout << "Figure_O destroyed" << std::endl;
}


