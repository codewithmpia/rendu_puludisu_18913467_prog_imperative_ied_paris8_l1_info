/* *******************************************************
 * Nom           : main.c
 * Rôle          : Lis les informations dans un fichier
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

 int main() {
     FILE *file = fopen("cx15.3.data", "r");  // Ouverture du fichier contenant les noms
     if (!file) {  // Vérification de l'ouverture réussie du fichier
         fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");  // Message d'erreur en cas d'échec
         return 1;  // Retourne 1 pour indiquer une erreur
     }

     char names[MAX_NAMES][MAX_NAME_LENGTH];  // Déclaration du tableau pour stocker les noms
     int count = 0;  // Initialisation du compteur de noms

     // Lecture des noms depuis le fichier jusqu'à la fin du fichier (EOF)
     // EOF = “End Of File” (fin de fichier).
     while (fscanf(file, "%s", names[count]) != EOF) {
         count++;  // Incrémentation du compteur de noms
     }

     fclose(file);  // Fermeture du fichier

     // Boucle à travers tous les noms lus
     for (int i = 0; i < count; i++) {
         printf("%s\n", names[i]);  // Affichage de chaque nom
     }

     return 0;  // Retourne 0 pour indiquer que le programme s'est terminé avec succès
 }
