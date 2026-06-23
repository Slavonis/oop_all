#include "triangle.h"

void Triangle::accept(shape_visitor* visitor) {
    visitor->visit(this); // Visitor understands this is a Circle*
}
