/* *******************************************************
 * Nom           : main.c
 * Rôle          : Lis les informations dans un fichier
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

    for (int i = 0; i < count; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
