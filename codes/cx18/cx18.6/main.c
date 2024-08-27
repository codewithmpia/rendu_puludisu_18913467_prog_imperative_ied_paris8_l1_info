/* *******************************************************
 * Nom           : main.c
 * Rôle          : Déportation de fonctions de gestion de listes
 *                 dans une bibliothèque dynamique
 * Auteur        : Mpia Mimpiya PULUDISU
 * Version       : 1.0
 * Date          : 2024-08-26
 * Licence       : L1 PROGC
 * *******************************************************
 * Compilation   : gcc -c -fPIC list.c -o list.o
 *                 gcc -shared -o list.so list.o
 *                 gcc -o main main.c -L. -llist
 * Usage         : ./main
 * *******************************************************/
#include "list.h"

int main(int argc, char *argv[]) {
    list L = NULL;
    int k;
    for (k = 'h'; k >= 'a'; k--) {
        L = cons(k, L);
    }
    putlist(L);
    return 0;
}
