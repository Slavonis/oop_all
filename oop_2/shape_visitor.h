#ifndef SHAPE_VISITOR_H
#define SHAPE_VISITOR_H

class Circle;
class Rectangle;
class Line;
class Ellips;
class Triangle;
class Parallel;

class shape_visitor
{
public:
    virtual ~shape_visitor() = default;

    virtual void visit(Circle* circle) = 0;
    virtual void visit(Rectangle* rectangle) = 0;
    virtual void visit(Line* line) = 0;
    virtual void visit(Ellips* ellips) = 0;
    virtual void visit(Triangle* triangle) = 0;
    virtual void visit(Parallel* parallel) = 0;
};

#endif // SHAPE_VISITOR_H
