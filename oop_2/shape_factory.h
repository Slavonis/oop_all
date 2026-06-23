#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H
#include "figure.h"
#include "shapes_enum.h"
#include <vector>

class shape_factory
{
public:
    shape_factory();
    static figure* createShape(shape_t type, const std::vector<int>& params);
};

#endif // SHAPE_FACTORY_H
