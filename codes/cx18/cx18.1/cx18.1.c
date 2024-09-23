/* *******************************************************
 * Nom           : cx18.1.c
 * Rôle          : Recoder la fonction putlist() pour afficher la liste en ordre inverse
 * Auteur        : Mpia Mimpiya PULUDISU
 * Version       : 1.0
 * Date          : 2024-08-26
 * Licence       : L1 PROGC
 * *******************************************************
 * Compilation   : gcc -W cx18.1.c -o main
 * Usage         : ./main
 * *******************************************************/

#include <stdio.h>
#include <stdlib.h>

// Définition d'une structure de noeud pour une liste chaînée
typedef struct node {
    int car;            // Valeur du noeud
    struct node *cdr;   // Pointeur vers le noeud suivant
} *list;                // Définition d'un type de pointeur vers un noeud, appelé 'list'

// Fonction pour créer un nouveau noeud et l'ajouter à la fin de la liste
list cons(int car, list L) {
    list new = malloc(sizeof(struct node)); // Allocation de mémoire pour un nouveau noeud
    if (!new) {                             // Vérification de l'allocation réussie
        fprintf(stderr, "cons : manque de RAM\n"); // Message d'erreur en cas d'échec
        exit(1);                           // Terminaison du programme en cas d'échec
    }
    new->car = car;   // Initialisation de la valeur du noeud
    new->cdr = NULL;  // Le pointeur 'cdr' est initialisé à NULL

    if (!L) {         // Si la liste est vide, retourne le nouveau noeud
        return new;
    }

    list temp = L;    // Temporaire pour parcourir la liste
    while (temp->cdr) { // Parcours jusqu'à la fin de la liste
        temp = temp->cdr;
    }
    temp->cdr = new;  // Ajout du nouveau noeud à la fin de la liste
    return L;         // Retourne la liste mise à jour
}

// Fonction pour afficher les éléments de la liste
void putlist(list L) {
    if (!L) return;             // Si la liste est vide, on retourne
    printf("%c ", L->car);      // Affichage de la valeur du noeud courant
    putlist(L->cdr);            // Appel récursif pour afficher le reste de la liste
}

// Fonction principale
int main() {
    list L = NULL;              // Initialisation de la liste à NULL (vide)
    int k;
    for (k = 'h'; k >= 'a'; k--) { // Boucle pour ajouter les caractères de 'h' à 'a' dans la liste
        L = cons(k, L);         // Ajout de chaque caractère à la fin de la liste
    }
    putlist(L);                 // Affichage de la liste
    printf("\n");               // Ajout d'une nouvelle ligne pour une meilleure lisibilité
    return 0;                   // Fin du programme
}
