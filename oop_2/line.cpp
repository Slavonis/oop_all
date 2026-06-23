#include "line.h"

void Line::accept(shape_visitor* visitor) {
    visitor->visit(this); // Visitor understands this is a Circle*
}
