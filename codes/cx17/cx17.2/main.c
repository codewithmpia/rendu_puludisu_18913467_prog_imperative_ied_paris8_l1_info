/* *******************************************************
 * Nom           : main.c
 * Rôle          : Lis les mots dans un fichier et exclue les 
 *                 mots figurant la stoplist
 * Auteur        : Mpia Mimpiya PULUDISU
 * Version       : 1.0
 * Date          : 2024-08-26
 * Licence       : L1 PROGC
 * *******************************************************
 * Compilation   : gcc -Wall main.c -o main
 * Usage         : ./main
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50
#define MAX_STOPLIST 100

int is_in_stoplist(char *word, char stoplist[][MAX_NAME_LENGTH], int stoplist_count) {
    for (int i = 0; i < stoplist_count; i++) {
        if (strcmp(word, stoplist[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
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

    FILE *stoplist_file = fopen("stoplist.txt", "r");
    if (!stoplist_file) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier stoplist\n");
        return 1;
    }

    char stoplist[MAX_STOPLIST][MAX_NAME_LENGTH];
    int stoplist_count = 0;

    while (fscanf(stoplist_file, "%s", stoplist[stoplist_count]) != EOF) {
        stoplist_count++;
    }

    fclose(stoplist_file);

    for (int i = 0; i < count; i++) {
        if (!is_in_stoplist(names[i], stoplist, stoplist_count)) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
