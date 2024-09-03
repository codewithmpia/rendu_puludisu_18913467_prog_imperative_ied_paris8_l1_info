#include <stdio.h>

int main() {
    FILE *file = fopen("fichier.txt", "r");
    if (file == NULL) {
        printf("Une erreur s'est produite lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Déclarez un tableau pour stocker chaque ligne
    char line[256];  

    // Lire et afficher chaque ligne du fichier
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    // Fermer le fichier après la lecture
    fclose(file);  
    return 0;
}
