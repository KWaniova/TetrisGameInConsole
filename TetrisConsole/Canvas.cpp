#include "include/Canvas.h"
#include "include/Config.h"
#include <iostream>

using namespace std;


Canvas::Canvas(int _height, int _width, point_type _empty_char) {
    height = _height;
    width = _width;
    empty_char = _empty_char;
    canvas = get_empty_canvas();
};

Canvas::Canvas() {
    height = Config::get_instance().get_default_canvas_height();
    width = Config::get_instance().get_default_canvas_width();
    empty_char = Config::get_instance().get_default_empty_symbol();
    canvas = get_empty_canvas();
};

Canvas::~Canvas() {
    canvas.clear();
}

Canvas::canvas_type Canvas::get_empty_canvas() {
    canvas_type empty_canvas;
    empty_canvas.resize(height);
    for (int row = 0; row < height; row++)
        empty_canvas[row].resize(width);

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            empty_canvas[row][col] = empty_char;


    return empty_canvas;
}

Canvas::point_type Canvas::get_empty_char() {
    return empty_char;
}

bool Canvas::is_point_empty(Point point) {
    return canvas[point.get_x()][point.get_y()] == empty_char;
}

Canvas::canvas_type Canvas::get_canvas() const {
    Canvas::canvas_type canvas_copy(height);
    for (int row = 0; row < height; row++) {
        canvas_copy[row].resize(width);
        for (int col = 0; col < width; col++)
            canvas_copy[row][col] = canvas[row][col];
    }
    return canvas_copy;
}

void Canvas::print_canvas_edge()
{
    for (int i = 0; i < width; i++)
        std::cout << "= ";
    std::cout << std::endl;
};

void print_canvas(Canvas &canvas)
{
    canvas.print_canvas_edge();
    for (auto row : canvas.get_canvas())
    {
        for (auto element : row)
            std::cout << element << " ";
        std::cout << std::endl;
    }
    canvas.print_canvas_edge();
}

void Canvas::print()
{
    print_canvas(*this);
};

void Canvas::draw_points(Canvas::figure_type points, point_type color) {
    for (auto point : points)
        if(is_point_empty(point)){
            canvas[point.get_x()][point.get_y()] = color;
        }
}

int Canvas::get_height() {
    return height;
}

int Canvas::get_width() {
    return width;
}

bool Canvas::is_row_full(int row) {
    for(int col = 0; col < width; col++){
        if(canvas[row][col] == empty_char){
            return false;
        }
    }
    return true;
}


bool Canvas::is_point_on_canvas(Point point){
    return point.get_x() >= 0 && point.get_x() < height && point.get_y() >= 0 && point.get_y() < width;
}


void Canvas::set_canvas(canvas_type _canvas) {
    canvas = _canvas;
}

