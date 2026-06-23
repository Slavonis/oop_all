#ifndef PARALLEL_H
#define PARALLEL_H
#include "figure.h"
#include <QMath.h>

class Parallel : public figure
{
public:
    Parallel(int x1, int y1, int x2, int y2, int x3, int y3) : x1(x1), x2(x2), y1(y1), y2(y2), x3(x3), y3(y3)
    {
        double d12 = qPow(x2-x1, 2) + qPow(y2-y1, 2);
        double d23 = qPow(x3-x2, 2) + qPow(y3-y2, 2);
        double d13 = qPow(x3-x1, 2) + qPow(y3-y1, 2);
        if (d13 >= d12 && d13 >= d23) {
            x4 = x1 + x3 - x2;
            y4 = y1 + y3 - y2;
        } else if (d12 >= d23 && d12 >= d13) {
            x4 = x1 + x2 - x3;
            y4 = y1 + y2 - y3;
        } else {
            x4 = x2 + x3 - x1;
            y4 = y2 + y3 - y1;
        }
    }
    unsigned int Area() const override
    {
        int area = qAbs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
        return (unsigned int)area;
    }
    unsigned int Perimeter() const override
    {
        double side1 = qSqrt(qPow(x2 - x1, 2) + qPow(y2 - y1, 2));
        double side2 = qSqrt(qPow(x3 - x2, 2) + qPow(y3 - y2, 2));
        return (unsigned int)(2 * (side1 + side2));
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
    int getX4(){
        return x4;
    }
    int getY4(){
        return y4;
    }
    void accept(shape_visitor* visitor) override;
private:
    int x1;
    int x2;
    int y1;
    int y2;
    int x3;
    int y3;
    int x4;
    int y4;
};

#endif // PARALLEL_H
