/* *******************************************************
 * Nom           : main.c
 * Rôle          : Déportation de fonctions de gestion de listes
 *                 dans une bibliothèque dynamique
 * Auteur        : Mpia Mimpiya PULUDISU
 * Version       : 1.0
 * Date          : 2024-08-26
 * Licence       : L1 PROGC
 * *******************************************************
 * Compilation   : gcc -c -fPIC list.c -o list.o
 *                 gcc -shared -o list.so list.o
 *                 gcc -o main main.c -L. -llist
 * Usage         : Pour exécuter le programme, nous devons nous assurer que le système peut
                trouver la bibliothèque dynamique. Nous définissons la variable d’environnement
                LD_LIBRARY_PATH pour l'inclure dans le répertoire courant :

                export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
                ./main
 * *******************************************************/

 // Inclusion du fichier d'en-tête "list.h" qui contient les définitions et déclarations pour les listes chaînées
 #include "list.h"

 int main(int argc, char *argv[]) {
     list L = NULL;  // Initialiser la liste à NULL
     int k;
     // inversion des elements de la listes, on aura:  h g f e d c b a
     for (k = 'h'; k >= 'a'; k--) {
         L = cons(k, L);  // Ajouter chaque caractère de 'h' à 'a' en tête de liste
     }
     putlist(L);  // Afficher les éléments de la liste
     return 0;  // Retourner 0 pour indiquer que le programme s'est terminé avec succès
 }
