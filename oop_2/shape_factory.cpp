#include "shape_factory.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "ellips.h"
#include "triangle.h"
#include "parallel.h"

figure* shape_factory::createShape(shape_t type, const std::vector<int>& params) {
    switch (type) {
    case CIRCLE:
        if (params.size() >= 3)
            return new Circle(params[0], params[1], params[2]); // r, x1, y1
        break;

    case RECTANGLE:
        if (params.size() >= 4)
            return new Rectangle(params[0], params[1], params[2], params[3]); // x1, y1, x2, y2
        break;

    case LINE:
        if (params.size() >= 4)
            return new Line(params[0], params[1], params[2], params[3]); // x1, y1, x2, y2
        break;

    case ELLIPS:
        if (params.size() >= 4)
            return new Ellips(params[0], params[1], params[2], params[3]); // x1, y1, width, height
        break;

    case TRIANG:
        if (params.size() >= 6)
            return new Triangle(params[0], params[1], params[2], params[3], params[4], params[5]); // x1, y1, x2, y2, x3, y3
        break;

    case PARALLEL:
        if (params.size() >= 6)
            return new Parallel(params[0], params[1], params[2], params[3], params[4], params[5]); // x1, y1, x2, y2, x3, y3
        break;
    }
    return nullptr; // Return null if parameters don't match or type is unrecognized
}
