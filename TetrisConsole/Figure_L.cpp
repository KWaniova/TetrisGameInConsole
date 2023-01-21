
#include "include/Figure_L.h"
#include "include/Figure.h"
#include "include/Canvas.h"
#include <iostream>

Figure_L::Figure_L(Canvas canvas) : Figure(canvas, 'L', std::vector<Point>{}) {
    std::cout << "Figure_L created" << std::endl;
    int canvas_center_width = (canvas.get_width()-1) / 2;
    Point point1(0, canvas_center_width);
    Point point2(1, canvas_center_width);
    Point point3(1, canvas_center_width+1);
    set_block_coordinates(std::vector<Point>{point1, point2, point3});
}

Figure_L::~Figure_L() {
    std::cout << "Figure_L destroyed" << std::endl;
}


