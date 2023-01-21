//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H


#include <vector>
#include "Point.h"

class Canvas {
    std::vector<std::vector<char>> canvas;
    int width;
    int height;
    char empty_char;
public:
    void print_canvas_edge();
    Canvas(int _height, int _width, char _empty_char);
    ~Canvas();
    void print();
    char get_empty_char();
    void set_canvas(std::vector<std::vector<char>> _canvas);
    void draw_points(std::vector<Point> points, char color);
    bool is_point_empty(Point point);
    bool is_row_full(int row);
    bool is_point_on_canvas(Point point);
    int get_height();
    int get_width();

    std::vector<std::vector<char>> get_canvas() const;
};

#endif //UNTITLED_CANVAS_H
