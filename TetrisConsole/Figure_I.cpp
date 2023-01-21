
#include "include/Figure_I.h"
#include "include/Figure.h"
#include "include/Canvas.h"
#include <iostream>

Figure_I::Figure_I(Canvas canvas) : Figure(canvas, 'i', std::vector<Point>{}) {
    std::cout << "Figure_I created" << std::endl;
    int canvas_center_width = (canvas.get_width() -1) / 2;
    Point point1(0, canvas_center_width );
    Point point2(1, canvas_center_width );
    Point point3(2, canvas_center_width);
    Point point4(3, canvas_center_width );
    set_block_coordinates(std::vector<Point>{point1, point2, point3, point4});
}

Figure_I::~Figure_I() {
    std::cout << "Figure_I destroyed" << std::endl;
}


