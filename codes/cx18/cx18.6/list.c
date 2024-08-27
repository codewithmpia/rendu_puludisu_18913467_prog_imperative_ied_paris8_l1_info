#include <stdio.h>
#include "list.h"

list cons(int car, list L) {
    list new = malloc(sizeof(struct node));
    if (!new) {
        fprintf(stderr, "cons : manque de RAM\n");
        exit(1);
    }
    new->car = car;
    new->cdr = L;
    return new;
}

void putlist(list L) {
    L = reverse_list(L);
    while (L != NULL) {
        printf("%c ", L->car);
        L = L->cdr;
    }
    printf("\n");
}

list reverse_list(list L) {
    list prev = NULL;
    list current = L;
    list next = NULL;

    while (current != NULL) {
        next = current->cdr;
        current->cdr = prev;
        prev = current;
        current = next;
    }
    return prev;
}
