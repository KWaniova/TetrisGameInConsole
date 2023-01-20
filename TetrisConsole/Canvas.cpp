#include "include/Canvas.h"
#include <iostream>

using namespace std;

char EMPTY_CHAR = ' ';

Canvas::Canvas(int _height, int _width) {
    canvas = new char *[_height];
    for (int row = 0; row < _height; row++)
        canvas[row] = new char[_width];

    for (int row = 0; row < _height; row++)
        for (int col = 0; col < _width; col++)
            canvas[row][col] = EMPTY_CHAR;

    height = _height;
    width = _width;
};

bool Canvas::is_point_empty(Point point) {
    return canvas[point.get_x()][point.get_y()] == EMPTY_CHAR;
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

