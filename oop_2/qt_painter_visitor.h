#ifndef QT_PAINTER_VISITOR_H
#define QT_PAINTER_VISITOR_H

#include "shape_visitor.h"
#include <QPainter>

class qt_painter_visitor : public shape_visitor
{
private:
    QPainter& m_painter;

public:
    explicit qt_painter_visitor(QPainter& painter) : m_painter(painter) {}

    void visit(Circle* circ) override;
    void visit(Rectangle* rect) override;
    void visit(Line* line) override;
    void visit(Ellips* ellip) override;
    void visit(Triangle* triang) override;
    void visit(Parallel* parallel) override;
};

#endif // QT_PAINTER_VISITOR_H
