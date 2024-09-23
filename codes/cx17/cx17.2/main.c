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
#include <stdio.h>   // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>  // Inclusion de la bibliothèque standard pour la gestion de la mémoire
#include <string.h>  // Inclusion de la bibliothèque pour la manipulation des chaînes de caractères

#define MAX_NAMES 100        // Définition de la taille maximale du tableau de noms
#define MAX_NAME_LENGTH 50   // Définition de la longueur maximale d'un nom
#define MAX_STOPLIST 100     // Définition de la taille maximale du tableau de mots à exclure

// Fonction pour vérifier si un mot est dans la liste des mots à exclure
int is_in_stoplist(char *word, char stoplist[][MAX_NAME_LENGTH], int stoplist_count) {
    for (int i = 0; i < stoplist_count; i++) {  // Boucle à travers la liste des mots à exclure
        if (strcmp(word, stoplist[i]) == 0) {   // Comparaison du mot avec chaque mot de la liste
            return 1;  // Retourne 1 si le mot est trouvé dans la liste
        }
    }
    return 0;  // Retourne 0 si le mot n'est pas trouvé dans la liste
}

int main() {
    FILE *file = fopen("cx15.3.data", "r");  // Ouverture du fichier contenant les noms
    if (!file) {  // Vérification de l'ouverture réussie du fichier
        fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");  // Message d'erreur en cas d'échec
        return 1;  // Retourne 1 pour indiquer une erreur
    }

    char names[MAX_NAMES][MAX_NAME_LENGTH];  // Déclaration du tableau pour stocker les noms
    int count = 0;  // Initialisation du compteur de noms

     // Lecture des noms depuis le fichier jusqu'à la fin du fichier (EOF)
     while (fscanf(file, "%s", names[count]) != EOF) {
        count++;  // Incrémentation du compteur de noms
    }

    fclose(file);  // Fermeture du fichier

    FILE *stoplist_file = fopen("stoplist.txt", "r");  // Ouverture du fichier contenant la liste des mots à exclure
    if (!stoplist_file) {  // Vérification de l'ouverture réussie du fichier
        fprintf(stderr, "Erreur lors de l'ouverture du fichier stoplist\n");  // Message d'erreur en cas d'échec
        return 1;  // Retourne 1 pour indiquer une erreur
    }

    char stoplist[MAX_STOPLIST][MAX_NAME_LENGTH];  // Déclaration du tableau pour stocker les mots à exclure
    int stoplist_count = 0;  // Initialisation du compteur de mots à exclure

    // Lecture des mots à exclure depuis le fichier jusqu'à la fin du fichier (EOF)
    while (fscanf(stoplist_file, "%s", stoplist[stoplist_count]) != EOF) {
        stoplist_count++;  // Incrémentation du compteur de mots à exclure
    }

    fclose(stoplist_file);  // Fermeture du fichier

    // Boucle à travers tous les noms lus
    for (int i = 0; i < count; i++) {
        // Affichage du nom s'il n'est pas dans la liste des mots à exclure
        if (!is_in_stoplist(names[i], stoplist, stoplist_count)) {
            printf("%s\n", names[i]);  // Affichage du nom
        }
    }

    return 0;  // Retourne 0 pour indiquer que le programme s'est terminé avec succès
 }
