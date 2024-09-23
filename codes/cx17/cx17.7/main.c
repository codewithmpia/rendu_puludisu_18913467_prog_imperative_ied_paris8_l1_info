/* *******************************************************
 * Nom           : main.c
 * Rôle          : Lis les mots dans un fichier et exclue les
 *                 mots figurant la stoplist (adaptation de cx15.3)
 * Auteur        : Mpia Mimpiya PULUDISU
 * Version       : 1.0
 * Date          : 2024-08-26
 * Licence       : L1 PROGC
 * *******************************************************
 * Compilation   : gcc -c -fPIC list.c -o list.o
                   gcc -shared -o list.so list.o
                   gcc -o main main.c -L. -llist

                   OU

                   gcc -W main.c list.c
                   ./main

 * Usage         : export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
 *                 ./main
 * *******************************************************/

 #include <stdio.h>   // Inclusion de la bibliothèque standard d'entrée/sortie
 #include <stdlib.h>  // Inclusion de la bibliothèque standard pour la gestion de la mémoire
 #include <string.h>  // Inclusion de la bibliothèque pour la manipulation des chaînes de caractères
 #include "list.h"    // Inclusion du fichier d'en-tête "list.h" contenant les déclarations de la liste chaînée

 #define MAX_NAMES 100        // Définition de la taille maximale du tableau de noms
 #define MAX_NAME_LENGTH 50   // Définition de la longueur maximale d'un nom

 int main(int argc, char *argv[]) {
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

     // Détermination du nom du fichier de la liste des mots à exclure
     const char *stoplist_filename = (argc > 1) ? argv[1] : "stoplist.txt";
     FILE *stoplist_file = fopen(stoplist_filename, "r");  // Ouverture du fichier contenant la liste des mots à exclure
     if (!stoplist_file) {  // Vérification de l'ouverture réussie du fichier
         fprintf(stderr, "Erreur lors de l'ouverture du fichier stoplist\n");  // Message d'erreur en cas d'échec
         return 1;  // Retourne 1 pour indiquer une erreur
     }

     list stoplist = NULL;  // Initialisation de la liste des mots à exclure à NULL (vide)
     char word[MAX_NAME_LENGTH];  // Déclaration d'un tableau pour stocker chaque mot lu

     // Lecture des mots à exclure depuis le fichier jusqu'à la fin du fichier (EOF)
     while (fscanf(stoplist_file, "%s", word) != EOF) {
         stoplist = cons(word, stoplist);  // Ajout de chaque mot à la liste des mots à exclure
     }

     fclose(stoplist_file);  // Fermeture du fichier

     // Boucle à travers tous les noms lus
     for (int i = 0; i < count; i++) {
         // Affichage du nom s'il n'est pas dans la liste des mots à exclure
         if (!is_in_list(stoplist, names[i])) {
             printf("%s\n", names[i]);  // Affichage du nom
         }
     }

     return 0;  // Retourne 0 pour indiquer que le programme s'est terminé avec succès
 }
