#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QtMath>
#include "figure.h"

class Triangle: public figure
{
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : x1(x1), x2(x2), y1(y1), y2(y2), y3(y3), x3(x3)
    {}
    unsigned int Area() const override
    {
        int area = qAbs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2;
        return (unsigned int)area;
    }
    unsigned int Perimeter() const override
    {
        double side1 = qSqrt(qPow(x2 - x1, 2) + qPow(y2 - y1, 2));
        double side2 = qSqrt(qPow(x3 - x2, 2) + qPow(y3 - y2, 2));
        double side3 = qSqrt(qPow(x1 - x3, 2) + qPow(y1 - y3, 2));
        return (unsigned int)(side1 + side2 + side3);
    }
    int getX1(){
        return x1;
    }
    int getY1(){
        return y1;
    }
    int getX2(){
        return x2;
    }
    int getY2(){
        return y2;
    }
    int getX3(){
        return x3;
    }
    int getY3(){
        return y3;
    }
    void accept(shape_visitor* visitor) override;
private:
    int x1;
    int x2;
    int y1;
    int y2;
    int y3;
    int x3;
};

#endif // TRIANGLE_H
