#include "rectangle.h"

void Rectangle::accept(shape_visitor* visitor) {
    visitor->visit(this); // Visitor understands this is a Circle*
}
