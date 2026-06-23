#ifndef FIGURE_LIST_H
#define FIGURE_LIST_H
#include "figure.h"
#include "shapes_enum.h"


typedef struct list{
    shape_t shape_tp;
    figure* shape;
    list* next;
} list_t;

class figure_list
{
public:
    figure_list();
    void addCircle(int r, int x1, int y1);
    void addRectangle(int x1, int y1, int x2, int y2);
    void addLine(int x1, int y1, int x2, int y2);
    void addEllips(int x1, int y1, int width, int height);
    void addTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void addParallel(int x1, int y1, int x2, int y2, int x3, int y3);
    list_t* getList(){
        return head;
    }
    ~figure_list() {
        list_t* tail;
        while (head != nullptr){
            tail = head->next;
            delete(head);
            head = tail;
        }
    }
private:
    list_t* head;
};

#endif // FIGURE_LIST_H
