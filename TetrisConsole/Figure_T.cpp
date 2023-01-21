
#include "include/Figure_T.h"
#include "include/Figure.h"
#include "include/Canvas.h"
#include <iostream>

Figure_T::Figure_T(Canvas canvas) : Figure(canvas, 'T', std::vector<Point>{}) {
    std::cout << "Figure_T created" << std::endl;
    int canvas_center_width = canvas.get_width() / 2;
    Point point1(0, canvas_center_width -1);
    Point point2(0, canvas_center_width );
    Point point3(0, canvas_center_width + 1);
    Point point4(1, canvas_center_width );
    set_block_coordinates(std::vector<Point>{point1, point2, point3, point4});
}

Figure_T::~Figure_T() {
    std::cout << "Figure_T destroyed" << std::endl;
}


