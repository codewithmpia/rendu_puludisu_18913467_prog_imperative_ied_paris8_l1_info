/* *******************************************************
 * Nom           : cx18.1.c
 * Rôle          : Affiche la liste en ordre inverse
 * Auteur        : Mpia Mimpiya PULUDISU
 * Version       : 1.0
 * Date          : 2024-08-26
 * Licence       : L1 PROGC
 * *******************************************************
 * Compilation   : gcc -W cx18.1.c -o main
 * Usage         : ./main
 * *******************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int car;
    struct node *cdr;
} *list;

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
    if (!L) return; // nil : fin de liste
    printf("%c ", L->car);
    putlist(L->cdr);
}

int main(int k) {
    list L = NULL;
    for (k = 'a'; k < 'i'; k++) {
        L = cons(k, L);
    }
    putlist(L);
    return 0;
}
