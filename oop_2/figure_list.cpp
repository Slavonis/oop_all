#include "figure_list.h"
#include "shape_factory.h"


figure_list::figure_list() : head(nullptr) {}


void figure_list::addShape(shape_t type, const std::vector<int>& params) {
    figure* newShape = shape_factory::createShape(type, params);

    if (newShape) {
        list_t* newNode = new list_t;
        newNode->shape_tp = type;
        newNode->shape = newShape;
        newNode->next = head;
        head = newNode;
    }
}
