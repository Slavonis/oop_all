#include "parallel.h"

void Parallel::accept(shape_visitor* visitor) {
    visitor->visit(this); // Visitor understands this is a Circle*
}
