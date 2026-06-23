#ifndef ELLIPS_H
#define ELLIPS_H
#include "figure.h"
#include <math.h>

class Ellips: public figure
{
public:
    Ellips(int x1, int y1, int width, int height) : width(width), height(height), x1(x1), y1(y1)
    { }
    unsigned int Area() const override
    {
        return width * height * 3.14;
    }
    unsigned int Perimeter() const override
    {
        return 2 * 3.14 * sqrt((pow(width, 2) + pow(height, 2))/8);
    }
    int getX1(){
        return x1;
    }
    int getY1(){
        return y1;
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
    int y1;
    int width;
    int height;
};

#endif // ELLIPS_H
