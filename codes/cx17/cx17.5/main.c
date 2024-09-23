#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50
#define MAX_REFERENCES 100  // Nombre maximum de références par mot
#define MAX_STOPLIST 100

// Définition de la structure pour les noms et leurs références
struct Nom {
    char nom[MAX_NAME_LENGTH];
    char categorie[MAX_NAME_LENGTH];
    char references[MAX_REFERENCES][MAX_NAME_LENGTH];  // Tableau de références
    int ref_count;  // Compteur du nombre de références
};

// Fonction pour vérifier si une référence existe déjà dans la liste des références d'un mot
int reference_exists(struct Nom *n, char *reference) {
    for (int i = 0; i < n->ref_count; i++) {
        if (strcmp(n->references[i], reference) == 0) {
            return 1;  // La référence est déjà présente
        }
    }
    return 0;  // La référence n'est pas trouvée
}

// Fonction pour ajouter une référence à un mot, si elle n'existe pas encore
void ajouter_reference(struct Nom *n, char *reference) {
    if (!reference_exists(n, reference)) {  // Si la référence n'existe pas
        strcpy(n->references[n->ref_count], reference);  // Ajout de la référence
        n->ref_count++;  // Incrémentation du compteur de références
    }
}

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
        noms[count].ref_count = 0;  // Initialisation du compteur de références à 0
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
        // Si le mot n'est pas dans la liste des mots à exclure
        if (!is_in_stoplist(noms[i].nom, stoplist, stoplist_count)) {
            printf("Nom : %s, Catégorie : %s\n", noms[i].nom, noms[i].categorie);
            
            // Simulation de l'ajout de références pour chaque nom
            ajouter_reference(&noms[i], "ref1");
            ajouter_reference(&noms[i], "ref2");
            ajouter_reference(&noms[i], "ref1");  // Tentative de doublon
            
            // Affichage des références pour ce nom
            printf("Références : ");
            for (int j = 0; j < noms[i].ref_count; j++) {
                printf("%s ", noms[i].references[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
