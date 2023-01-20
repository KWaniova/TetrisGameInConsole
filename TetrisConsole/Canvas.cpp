#include "include/Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int _height, int _width) {
    canvas = new char *[_height];
    for (int row = 0; row < _height; row++)
        canvas[row] = new char[_width];

    for (int row = 0; row < _height; row++)
        for (int col = 0; col < _width; col++)
            canvas[row][col] = ' ';

    height = _height;
    width = _width;
};

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
    std::cout << "Canvas destroyed" << std::endl;
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

int Canvas::get_height() {
    return height;
}

int Canvas::get_width() {
    return width;
}

