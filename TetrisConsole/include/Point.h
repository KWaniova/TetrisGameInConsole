//
// Created by Krystyna Waniova on 10.01.2023.
//

#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H


class Point {
    int x, y;
public:
    Point();
    Point(int _x, int _y);
    int get_x();
    int get_y();
    void set_x(int _x);
    void set_y(int _y);
    void print();

};

#endif //UNTITLED_POINT_H
