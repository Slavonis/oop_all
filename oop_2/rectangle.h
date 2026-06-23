#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include <math.h>

class Rectangle : public figure
{
public:
    Rectangle(int x1, int y1, int x2, int y2) : x1(x1), x2(x2), y1(y1), y2(y2)
    {
        this->height = abs(y1-y2);
        this->width = abs(x2-x1);
    }
    unsigned int Area() const override
    {
        return width * height;
    }
    unsigned int Perimeter() const override
    {
        return width * 2 + height * 2;
    }
    int getX(){
        return x1 > x2 ? x2 : x1;
    }
    int getY(){
        return y1 > y2 ? y2 : y1;
    }
    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }
    void accept(shape_visitor* visitor) override;
private:
    int x1;
    int x2;
    int y1;
    int y2;
    int width;
    int height;
};

#endif // RECTANGLE_H
