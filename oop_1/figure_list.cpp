#include "figure_list.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "ellips.h"
#include "triangle.h"
#include "parallel.h"

figure_list::figure_list() : head(nullptr) {}

void figure_list::addCircle(int r, int x1, int y1) {

    Circle* newCircle = new Circle(r, x1, y1);

    list_t* newNode = new list_t;
    newNode->shape_tp = CIRCLE;
    newNode->shape = newCircle;
    newNode->next = head;
    head = newNode;
}

void figure_list::addRectangle(int x1, int y1, int x2, int y2) {

    Rectangle* newRect = new Rectangle(x1, y1, x2, y2);

    list_t* newNode = new list_t;
    newNode->shape_tp = RECTANGLE;
    newNode->shape = newRect;
    newNode->next = head;
    head = newNode;
}

void figure_list::addLine(int x1, int y1, int x2, int y2) {

    Line* line = new Line(x1, y1, x2, y2);

    list_t* newNode = new list_t;
    newNode->shape_tp = LINE;
    newNode->shape = line;
    newNode->next = head;
    head = newNode;
}

void figure_list::addEllips(int x1, int y1, int width, int height) {

    Ellips* ellip = new Ellips(x1, y1, width, height);

    list_t* newNode = new list_t;
    newNode->shape_tp = ELLIPS;
    newNode->shape = ellip;
    newNode->next = head;
    head = newNode;
}


void figure_list::addTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    Triangle* triang = new Triangle(x1, y1, x2, y2, x3, y3);

    list_t* newNode = new list_t;
    newNode->shape_tp = TRIANG;
    newNode->shape = triang;
    newNode->next = head;
    head = newNode;
}

void figure_list::addParallel(int x1, int y1, int x2, int y2, int x3, int y3){
    Parallel* parallel = new Parallel(x1, y1, x2, y2, x3, y3);

    list_t* newNode = new list_t;
    newNode->shape_tp = PARALLEL;
    newNode->shape = parallel;
    newNode->next = head;
    head = newNode;
}
