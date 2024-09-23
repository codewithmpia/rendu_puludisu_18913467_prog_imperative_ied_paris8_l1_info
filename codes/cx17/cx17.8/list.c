#include <stdio.h>   // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>  // Inclusion de la bibliothèque standard pour la gestion de la mémoire
#include <string.h>  // Inclusion de la bibliothèque pour la manipulation des chaînes de caractères
#include "list.h"    // Inclusion du fichier d'en-tête "list.h" contenant les déclarations de la liste chaînée

// Fonction pour créer un nouveau noeud et l'ajouter en tête de liste
list cons(char *car, list L) {
    list new = malloc(sizeof(struct node));  // Allocation de mémoire pour un nouveau noeud
    if (!new) {  // Vérification de l'allocation réussie
        fprintf(stderr, "cons : manque de RAM\n");  // Message d'erreur en cas d'échec
        exit(1);  // Terminaison du programme en cas d'échec
    }
    new->car = strdup(car);  // Copie de la chaîne de caractères dans le nouveau noeud
    new->cdr = L;  // Le pointeur 'cdr' pointe vers l'ancienne tête de liste
    return new;  // Retourne le nouveau noeud, qui est maintenant la tête de liste
}

// Fonction pour afficher les éléments de la liste
void putlist(list L) {
    if (!L) return;  // nil : fin de liste
    putlist(L->cdr);  // Appel récursif pour afficher le reste de la liste
    printf("%s ", L->car);  // Affichage de la valeur du noeud courant
}

// Fonction pour vérifier si un mot est dans la liste
int is_in_list(list L, char *word) {
    while (L) {  // Boucle à travers la liste
        if (strcmp(L->car, word) == 0) {  // Comparaison du mot avec la valeur du noeud courant
            return 1;  // Retourne 1 si le mot est trouvé dans la liste
        }
        L = L->cdr;  // Passe au noeud suivant
    }
    return 0;  // Retourne 0 si le mot n'est pas trouvé dans la liste
}
