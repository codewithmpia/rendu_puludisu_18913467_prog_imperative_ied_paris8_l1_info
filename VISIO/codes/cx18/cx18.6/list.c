// Inclusion de la bibliothèque standard pour les entrées/sorties (printf, fprintf, etc.)
#include <stdio.h>
// Inclusion du fichier d'en-tête "list.h" qui contient les définitions et déclarations pour les listes chaînées
#include "list.h"

// Fonction pour ajouter un élément en tête de liste
list cons(int car, list L) {
    list new = malloc(sizeof(struct node));  // Allouer de la mémoire pour un nouveau nœud
    if (!new) {
        fprintf(stderr, "cons : manque de RAM\n");  // Afficher un message d'erreur si l'allocation échoue
        exit(1);  // Quitter le programme en cas d'erreur
    }
    new->car = car;  // Initialiser la valeur du nouveau nœud
    new->cdr = L;  // Lier le nouveau nœud à la liste existante
    return new;  // Retourner le nouveau nœud
}

// Fonction pour afficher les éléments de la liste
void putlist(list L) {
    L = reverse_list(L);  // Inverser la liste pour l'affichage
    while (L != NULL) {
        printf("%c ", L->car);  // Afficher la valeur de chaque nœud
        L = L->cdr;  // Passer au nœud suivant
    }
    printf("\n");  // Nouvelle ligne après l'affichage de la liste
}

// Fonction pour inverser l'ordre des éléments de la liste
list reverse_list(list L) {
    list prev = NULL;  // Initialiser le pointeur vers le nœud précédent
    list current = L;  // Initialiser le pointeur vers le nœud actuel
    list next = NULL;  // Initialiser le pointeur vers le nœud suivant

    while (current != NULL) {
        next = current->cdr;  // Sauvegarder le nœud suivant
        current->cdr = prev;  // Inverser le lien du nœud actuel
        prev = current;  // Avancer le pointeur vers le nœud précédent
        current = next;  // Avancer le pointeur vers le nœud actuel
    }
    return prev;  // Retourner le nouveau premier nœud de la liste inversée
}
