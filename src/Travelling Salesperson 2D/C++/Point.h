#ifndef POINT_H
#define POINT_H
#include <cmath>

class Point {
    public:
    double x;
    double y;
    int index;
    Point *nextPoint;

    Point() {
        nextPoint = this;
    }

    Point(double x, double y, int i) {
        this->x = x;
        this->y = y;
        index = i;
        nextPoint = this;
    }

    double distance(Point *other) {
        double a = pow(x - other->x, 2);
        double b = pow(y - other->y, 2);
        return sqrt(a + b);
    }

    virtual bool operator==(const Point other) const {
        return this->index == other.index;
    }
    virtual bool operator!=(const Point other) const {
        return this->index != other.index;
    }
};
#endif
