#include "include/Canvas.h"
#include <iostream>

using namespace std;


Canvas::Canvas(int _height, int _width, char _empty_char) {
    canvas = new char *[_height];
    for (int row = 0; row < _height; row++)
        canvas[row] = new char[_width];

    for (int row = 0; row < _height; row++)
        for (int col = 0; col < _width; col++)
            canvas[row][col] = _empty_char;

    height = _height;
    width = _width;
    empty_char = _empty_char;
};

bool Canvas::is_point_empty(Point point) {
    return canvas[point.get_x()][point.get_y()] == empty_char;
}

char** Canvas::get_canvas() { //to get canvas that cant be modified
    char ** canvasCopy = new char *[height];
    for (int row = 0; row < height; row++)
        canvasCopy[row] = new char[width];

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            canvasCopy[row][col] = canvas[row][col];
    return canvasCopy;
}

void Canvas::print_canvas_edge()
{
    for (int i = 0; i < width; i++)
        std::cout << "= ";
    std::cout << std::endl;
};


Canvas::~Canvas() {
}

void Canvas::draw()
{
    print_canvas_edge();
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
            cout << canvas[row][col] << " ";
        cout << endl;
    };
    print_canvas_edge();
};

void Canvas::draw_points(std::vector<Point> points, char color) {
    for(int i = 0; i < points.size(); i++){
        if(is_point_empty(points[i])){
            canvas[points[i].get_x()][points[i].get_y()] = color;
        }
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


void Canvas::set_canvas(char **_canvas) {
    canvas = _canvas;
}

char Canvas::get_empty_char() {
    return empty_char;
}
