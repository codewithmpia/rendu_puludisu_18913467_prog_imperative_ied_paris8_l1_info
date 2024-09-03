#include <stdio.h>

int main () {
    // complete pour écrire dans un fichier
    FILE *file = fopen("sonika.txt", "w");
    if (file == NULL) {
        printf("Une erreur s'est produite lors de l'ouverture du fichier.");
        return 1;
    }

    fprintf(file, "ECRITURE DANS UN FICHIER\n");
    fprintf(file, "-------------------------\n");
    fprintf(file, "Je suis un geek.\n");
    fprintf(file, "Les aventures de tintin.\n");
    fclose(file);
    return 0;
}
