#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class Rectangle : public figure
{
public:
    Rectangle(int x1, int y1, int x2, int y2) : x1(x1), x2(x2), y1(y1), y2(y2)
    {
        this->height = y1-y2;
        this->width = x2-x1;
    }
    unsigned int Area() const override
    {
        return width * height;
    }
    unsigned int Perimeter() const override
    {
        return width * 2 + height * 2;
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
private:
    int x1;
    int x2;
    int y1;
    int y2;
    int width;
    int height;
};

#endif // RECTANGLE_H
