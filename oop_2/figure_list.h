#ifndef FIGURE_LIST_H
#define FIGURE_LIST_H
#include "figure.h"
#include "shapes_enum.h"
#include <vector>


typedef struct list{
    shape_t shape_tp;
    figure* shape;
    list* next;
} list_t;

class figure_list
{
public:
    figure_list();
    void addShape(shape_t type, const std::vector<int>& params);
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
