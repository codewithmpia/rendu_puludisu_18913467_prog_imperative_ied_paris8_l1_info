#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REFS 1000 // Définir une taille maximale pour les références
#define MAX_LINE_LENGTH 1000 // Définir une longueur maximale pour chaque ligne lue

// Structure pour stocker les références
typedef struct {
    char refs[MAX_REFS][100]; // Tableau de chaînes pour stocker les références
    int count; // Compteur de références
} RefList;

// Fonction pour vérifier si une référence existe déjà
int ref_exists(RefList *list, const char *ref) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->refs[i], ref) == 0) {
            return 1; // La référence existe déjà
        }
    }
    return 0; // La référence n'existe pas
}

// Fonction pour ajouter une référence si elle n'existe pas déjà
void ajoute_ref(RefList *list, const char *ref) {
    if (!ref_exists(list, ref)) {
        strcpy(list->refs[list->count], ref); // Copier la référence dans le tableau
        list->count++; // Incrémenter le compteur de références
    }
}

// Fonction pour traiter un fichier et ajouter ses lignes comme références
void process_file(const char *filename, RefList *list) {
    FILE *file = fopen(filename, "r"); // Ouvrir le fichier en mode lecture
    if (file == NULL) {
        perror("Error opening file"); // Afficher un message d'erreur si le fichier ne peut pas être ouvert
        exit(EXIT_FAILURE); // Quitter le programme avec un code d'erreur
    }

    char line[MAX_LINE_LENGTH];
    // Lire chaque ligne du fichier jusqu'à la fin du fichier (EOF)
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Enlever le caractère de nouvelle ligne
        ajoute_ref(list, line); // Ajouter la ligne comme référence
    }

    fclose(file); // Fermer le fichier
}

int main() {
    RefList list = { .count = 0 }; // Initialiser la liste des références

    // Traiter le fichier avec 50 paragraphes
    process_file("fichier.txt", &list);

    // Afficher les références pour vérifier
    for (int i = 0; i < list.count; i++) {
        printf("Référence %d: %s\n", i + 1, list.refs[i]);
    }

    return 0;
}
