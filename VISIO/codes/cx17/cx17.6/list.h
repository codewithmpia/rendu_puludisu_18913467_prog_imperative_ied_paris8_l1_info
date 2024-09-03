#ifndef LIST_H
#define LIST_H

typedef struct node {
    char *car;
    struct node *cdr;
} *list;

list cons(char *car, list L);
void putlist(list L);
int is_in_list(list L, char *word);

#endif
