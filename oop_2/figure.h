#ifndef FIGURE_H
#define FIGURE_H
#include "shape_visitor.h"

class figure
{
public:
    virtual unsigned int Area() const = 0;
    virtual unsigned int Perimeter() const = 0;
    //virtual void Show() const = 0;
    virtual ~figure() {};

    virtual void accept(shape_visitor* visitor) = 0;
};

#endif // FIGURE_H
