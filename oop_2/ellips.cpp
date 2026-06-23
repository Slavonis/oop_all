#include "ellips.h"

void Ellips::accept(shape_visitor* visitor) {
    visitor->visit(this); // Visitor understands this is a Circle*
}
