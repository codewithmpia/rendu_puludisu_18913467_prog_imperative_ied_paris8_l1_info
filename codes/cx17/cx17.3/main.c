#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50
#define MAX_STOPLIST 100

// Définition de la structure pour les noms
struct Nom {
    char nom[MAX_NAME_LENGTH];
    char categorie[MAX_NAME_LENGTH];  // Champ supplémentaire pour la catégorie
};

// Fonction pour vérifier si un mot est dans la liste des mots à exclure
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

    struct Nom noms[MAX_NAMES];  // Tableau de structures pour stocker les noms et catégories
    int count = 0;

    // Lecture des noms et des catégories depuis le fichier
    while (fscanf(file, "%s %s", noms[count].nom, noms[count].categorie) != EOF) {
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

    // Lecture des mots à exclure depuis le fichier
    while (fscanf(stoplist_file, "%s", stoplist[stoplist_count]) != EOF) {
        stoplist_count++;
    }

    fclose(stoplist_file);

    // Boucle à travers tous les noms lus
    for (int i = 0; i < count; i++) {
        // Affichage du nom et de sa catégorie s'il n'est pas dans la liste des mots à exclure
        if (!is_in_stoplist(noms[i].nom, stoplist, stoplist_count)) {
            printf("%s (%s)\n", noms[i].nom, noms[i].categorie);  // Affichage du nom avec la catégorie
        }
    }

    return 0;
}
