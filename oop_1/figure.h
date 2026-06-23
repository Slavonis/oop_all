#ifndef FIGURE_H
#define FIGURE_H

class figure
{
public:
    virtual unsigned int Area() const = 0;
    virtual unsigned int Perimeter() const = 0;
    //virtual void Show() const = 0;
    virtual ~figure() {};
};

#endif // FIGURE_H
