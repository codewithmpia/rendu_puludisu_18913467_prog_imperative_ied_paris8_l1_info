#ifndef LIST_H  // Si LIST_H n'est pas défini, alors définir LIST_H
#define LIST_H  // Définition de LIST_H pour éviter les inclusions multiples

// Définition de la structure de noeud pour une liste chaînée
typedef struct node {
    char *car;          // Pointeur vers une chaîne de caractères (valeur du noeud)
    struct node *cdr;   // Pointeur vers le noeud suivant
} *list;                // Définition d'un type de pointeur vers un noeud, appelé 'list'

// Déclaration de la fonction pour créer un nouveau noeud et l'ajouter en tête de liste
list cons(char *car, list L);

// Déclaration de la fonction pour afficher les éléments de la liste
void putlist(list L);

// Déclaration de la fonction pour vérifier si un mot est dans la liste
int is_in_list(list L, char *word);

#endif  // Fin de la conditionnelle #ifndef LIST_H
