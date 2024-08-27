#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct node {
    int car;
    struct node *cdr;
} *list;

list cons(int car, list L);
void putlist(list L);
list reverse_list(list L);

#endif


