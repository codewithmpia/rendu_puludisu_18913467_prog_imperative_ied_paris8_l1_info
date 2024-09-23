// Protection contre les inclusions multiples
//
/*
    La directive #ifndef en C et C++ signifie “if not defined” (si non défini).
    Elle est utilisée pour vérifier si un symbole (ou macro) n’a pas encore été défini.
    Si ce symbole n’est pas défini, le code entre #ifndef et #endif sera
    inclus par le préprocesseur.
*/
#ifndef LIST_H
#define LIST_H

// Inclusion de la bibliothèque standard pour les fonctions utilitaires générales (malloc, free, etc.)
#include <stdlib.h>
// Définition de la structure de données pour une liste chaînée
typedef struct node {
    int car;  // Valeur de l'élément de la liste
    struct node *cdr;  // Pointeur vers le prochain élément de la liste
} *list;  // Définition du type 'list' comme un pointeur vers un 'node'

// Déclaration des fonctions pour manipuler la liste chaînée
list cons(int car, list L);  // Fonction pour ajouter un élément en tête de liste
void putlist(list L);  // Fonction pour afficher les éléments de la liste
list reverse_list(list L);  // Fonction pour inverser l'ordre des éléments de la liste

#endif  // Fin de la protection contre les inclusions multiples
