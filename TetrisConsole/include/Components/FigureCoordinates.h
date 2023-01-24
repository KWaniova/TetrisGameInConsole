
#include "Point.h"

class FigureCoordinates {
    Point point1;
    Point point2;
    Point point3;
    Point point4;

public:

    FigureCoordinates();
    FigureCoordinates(Point point1, Point point2, Point point3, Point point4);
    ~FigureCoordinates();

    Point get_point1();
    Point get_point2();
    Point get_point3();
    Point get_point4();

    void set_point1(Point point1);
    void set_point2(Point point2);
    void set_point3(Point point3);
    void set_point4(Point point4);

    void print();

};
