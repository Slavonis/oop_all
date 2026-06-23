#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle: public figure
{
public:
    Circle(int r, int x1, int y1) : radius(r), x1(x1), y1(y1)
    { }
    unsigned int Area() const override
    {
        return radius * radius * 3.13;
    }
    unsigned int Perimeter() const override
    {
        return 2 * 3.14 * radius;
    }
    int getX1(){
        return x1;
    }
    int getY1(){
        return y1;
    }
    int getRadius(){
        return radius;
    }

    void accept(shape_visitor* visitor) override;
private:
    int x1;
    int y1;
    int radius;
};

#endif // CIRCLE_H
