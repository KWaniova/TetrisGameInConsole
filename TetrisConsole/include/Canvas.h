//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H


#include <vector>
#include "Point.h"
#include "Config.h"

class Canvas {
    using figure_type = std::vector<Point>;
    using point_type = Config::empty_point_type;

    using canvas_type = std::vector<std::vector<point_type>>;

    int height;
    int width;
    canvas_type canvas;
    point_type empty_char;
public:

    using public_point_type = point_type;

    Canvas();
    void print_canvas_edge();
    Canvas(int _height, int _width, point_type _empty_char);
    ~Canvas();
    void print();
    point_type get_empty_char();
    void set_canvas(canvas_type _canvas);
    void draw_points(figure_type points, point_type color);
    bool is_point_empty(Point point);
    bool is_row_full(int row);
    bool is_point_on_canvas(Point point);
    int get_height();
    int get_width();
    canvas_type get_empty_canvas();
    canvas_type get_canvas() const;
};

#endif //UNTITLED_CANVAS_H
