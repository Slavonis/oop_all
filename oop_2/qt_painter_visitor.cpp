#include "qt_painter_visitor.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "ellips.h"
#include "triangle.h"
#include "parallel.h"

void qt_painter_visitor::visit(Circle* circ) {
    m_painter.drawEllipse(circ->getX1(), circ->getY1(), circ->getRadius() * 2, circ->getRadius() * 2);
}

void qt_painter_visitor::visit(Rectangle* rect) {
    m_painter.drawRect(rect->getX(), rect->getY(), rect->getWidth(), rect->getHeight());
}

void qt_painter_visitor::visit(Line* line) {
    m_painter.drawLine(line->getX1(), line->getY1(), line->getX2(), line->getY2());
}

void qt_painter_visitor::visit(Ellips* ellip) {
    m_painter.drawEllipse(ellip->getX1(), ellip->getY1(), ellip->getWidth(), ellip->getHeight());
}

void qt_painter_visitor::visit(Triangle* triang) {
    m_painter.drawPolygon({QPointF(triang->getX1(), triang->getY1()),
                           QPointF(triang->getX2(), triang->getY2()),
                           QPointF(triang->getX3(), triang->getY3())});
}

void qt_painter_visitor::visit(Parallel* parallel) {
    m_painter.drawPolygon({QPointF(parallel->getX1(), parallel->getY1()),
                           QPointF(parallel->getX2(), parallel->getY2()),
                           QPointF(parallel->getX3(), parallel->getY3()),
                           QPointF(parallel->getX4(), parallel->getY4())});
}
