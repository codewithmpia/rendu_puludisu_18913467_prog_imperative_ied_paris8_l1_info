/* *******************************************************
 * Nom           : main.c
 * Rôle          : Lis les mots dans un fichier et exclue les 
 *                 mots figurant la stoplist (adaptation de cx15.3)
 * Auteur        : Mpia Mimpiya PULUDISU
 * Version       : 1.0
 * Date          : 2024-08-26
 * Licence       : L1 PROGC
 * *******************************************************
 * Compilation   : gcc -c -fPIC list.c -o list.o
                   gcc -shared -o list.so list.o
                   gcc -o main main.c -L. -llist
 * Usage         : export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
 *                 ./main
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50

int main(int argc, char *argv[]) {
    FILE *file = fopen("cx15.3.data", "r");
    if (!file) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    char names[MAX_NAMES][MAX_NAME_LENGTH];
    int count = 0;

    while (fscanf(file, "%s", names[count]) != EOF) {
        count++;
    }

    fclose(file);

    const char *stoplist_filename = (argc > 1) ? argv[1] : "stoplist.txt";
    FILE *stoplist_file = fopen(stoplist_filename, "r");
    if (!stoplist_file) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier stoplist\n");
        return 1;
    }

    list stoplist = NULL;
    char word[MAX_NAME_LENGTH];

    while (fscanf(stoplist_file, "%s", word) != EOF) {
        stoplist = cons(word, stoplist);
    }

    fclose(stoplist_file);

    for (int i = 0; i < count; i++) {
        if (!is_in_list(stoplist, names[i])) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
