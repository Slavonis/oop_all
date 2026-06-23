#ifndef LINE_H
#define LINE_H
#include "figure.h"

class Line : public figure
{
public:
    Line(int x1, int y1, int x2, int y2) : x1(x1), x2(x2), y1(y1), y2(y2)
    {}
    unsigned int Area() const override
    {
        return 0;
    }
    unsigned int Perimeter() const override
    {
        return 0;
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
    void accept(shape_visitor* visitor) override;
private:
    int x1;
    int x2;
    int y1;
    int y2;
};

#endif // LINE_H
