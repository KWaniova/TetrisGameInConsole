//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H


class Canvas {
    char **canvas;
    int width;
    int height;
public:
    void print_canvas_edge();
    Canvas(int _height, int _width);
    ~Canvas();
    void draw();
    void clear();
    char** get_canvas();

    int get_height();
    int get_width();
};

#endif //UNTITLED_CANVAS_H
