#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list cons(char *car, list L) {
    list new = malloc(sizeof(struct node));
    if (!new) {
        fprintf(stderr, "cons : manque de RAM\n");
        exit(1);
    }
    new->car = strdup(car);
    new->cdr = L;
    return new;
}

void putlist(list L) {
    if (!L) return; // nil : fin de liste
    putlist(L->cdr);
    printf("%s ", L->car);
}

int is_in_list(list L, char *word) {
    while (L) {
        if (strcmp(L->car, word) == 0) {
            return 1;
        }
        L = L->cdr;
    }
    return 0;
}
