/*
Ce petit programme simule un processeur avec une mémoire de
taille fixe. Il lit un fichier contenant des instructions et exécute ces
instructions, affichant les états de l'accumulateur (A) et du compteur de
programme (PC).

compilation: gcc -W cx25.0.c -o main
            ./main program.hex
*/

// Inclusion de la bibliothèque standard pour les entrées/sorties (printf, scanf, etc.)
#include <stdio.h>
// Inclusion de la bibliothèque standard pour les fonctions utilitaires générales (malloc, free, exit, etc.)
#include <stdlib.h>
 // Inclusion de la bibliothèque pour les opérations sur les chaînes de caractères (memset, memcpy, etc.)
#include <string.h>

// Définir la taille de la mémoire et l'adresse de début du programme
#define MEMORY_SIZE 256
#define PROGRAM_START 0x50  // Adresse de début du programme

// Déclaration de la mémoire et des registres
unsigned char memory[MEMORY_SIZE];  // Tableau représentant la mémoire
unsigned char A = 0;  // Accumulateur pour stocker les résultats des opérations
unsigned int PC = PROGRAM_START;  // Compteur de programme, commence à l'adresse de début

// Fonction pour charger un programme en mémoire à partir d'un fichier
void charger_programme(const char *nom_fichier) {
    FILE *file = fopen(nom_fichier, "r");  // Ouvrir le fichier en mode lecture
    if (!file) {
        // Afficher un message d'erreur si le fichier ne peut pas être ouvert
        perror("Échec de l'ouverture du fichier");
        // EXIT_FAILURE vient de <stdlib.h>
        exit(EXIT_FAILURE);  // Quitter le programme en cas d'erreur
    }

    int adresse;
    unsigned char valeur1, valeur2;
    // Lire les valeurs du fichier et les stocker en mémoire
    // La notation &adresse, &valeur1, et &valeur2 utilise l’opérateur d’adresse (&) en C
    // Cet opérateur (&) est utilisé pour obtenir l’adresse mémoire d’une variable.
    while (fscanf(file, "%x %hhx %hhx", &adresse, &valeur1, &valeur2) == 3) {
        if (adresse >= MEMORY_SIZE - 1) {
             // Afficher un message d'erreur si l'adresse est invalide
            fprintf(stderr, "Adresse invalide : %x\n", adresse);
            fclose(file);  // Fermer le fichier
            exit(EXIT_FAILURE);  // Quitter le programme en cas d'erreur
        }
        // Stocker la première valeur à l'adresse spécifiée
        memory[adresse] = valeur1;
        // Stocker la deuxième valeur à l'adresse suivante
        memory[adresse + 1] = valeur2;
    }

    fclose(file);  // Fermer le fichier après la lecture
}

// Fonction pour exécuter le programme chargé en mémoire
void executer() {
    while (PC < MEMORY_SIZE) {
        unsigned char opcode = memory[PC++];  // Lire l'opcode à l'adresse actuelle du compteur de programme
        unsigned char operand;

        // Exécuter l'instruction en fonction de l'opcode
        switch (opcode) {
            case 0x00: printf("Instruction HALT rencontrée. Arrêt de l'exécution.\n"); return;  // Arrêter l'exécution si l'opcode est 0x00
            case 0x40: A += memory[PC++]; break;  // Ajouter la valeur suivante à l'accumulateur
            case 0x41: A -= memory[PC++]; break;  // Soustraire la valeur suivante de l'accumulateur
            case 0x48: A = memory[PC++]; break;   // Charger la valeur suivante dans l'accumulateur
            case 0x49: A &= memory[PC++]; break;  // ET logique avec la valeur suivante
            case 0x4A: A |= memory[PC++]; break;  // OU logique avec la valeur suivante
            case 0x4B: A ^= memory[PC++]; break;  // OU exclusif logique avec la valeur suivante
            case 0x4C: A = ~A; break;             // Négation binaire de l'accumulateur
            case 0x4D: A <<= 1; break;            // Décalage à gauche de l'accumulateur
            case 0x4E: A >>= 1; break;            // Décalage à droite de l'accumulateur
            case 0x4F: A += 1; break;             // Incrémenter l'accumulateur
            case 0x50: A -= 1; break;             // Décrémenter l'accumulateur
            case 0x51: A *= 2; break;             // Multiplier l'accumulateur par 2
            case 0x52: A /= 2; break;             // Diviser l'accumulateur par 2
            case 0x53: A &= 0xFF; break;          // ET logique avec 0xFF (aucun effet)
            case 0x54: A |= 0xFF; break;          // OU logique avec 0xFF (mettre tous les bits à 1)
            default: printf("Opcode inconnu : %02x\n", opcode); return;  // Afficher un message d'erreur pour un opcode inconnu
        }

        // Afficher l'état du compteur de programme et de l'accumulateur après l'exécution
        printf("PC : %02x, A après exécution : %02x\n", PC - 1, A);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Afficher un message d'utilisation si le nombre d'arguments est incorrect
        fprintf(stderr, "Utilisation : %s <fichier programme>\n", argv[0]);
        return EXIT_FAILURE;  // Quitter le programme en cas d'erreur
    }

    memset(memory, 0, MEMORY_SIZE);  // Initialiser la mémoire à zéro
    charger_programme(argv[1]);  // Charger le programme en mémoire

    // Débogage : Afficher le contenu de la mémoire avant l'exécution
    printf("Contenu de la mémoire avant exécution :\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("%02x ", memory[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");

    executer();  // Exécuter le programme
    printf("Valeur finale de A : %02x\n", A);  // Afficher la valeur finale de l'accumulateur
    // Quitter le programme avec succès
    return EXIT_SUCCESS;
}
