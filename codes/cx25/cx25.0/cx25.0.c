/* *******************************************************
 * Nom           : cx25.0.c
 * Rôle          : Emulateur d'un programme de lecture numérique
 * Auteur        : Mpia Mimpiya PULUDISU
 * Version       : 1.0
 * Date          : 2024-08-26
 * Licence       : L1 PROGC
 * *******************************************************
 * Compilation   : gcc -Wall cx25.0.c -o main
 * Usage         : ./main program.hex
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 256
#define PROGRAM_START 0x50  // Adresse de début du programme

unsigned char memory[MEMORY_SIZE];
unsigned char A = 0;  // Accumulateur
// Compteur de programme, commence à l'adresse de début
unsigned int PC = PROGRAM_START;  

void charger_programme(const char *nom_fichier) {
    FILE *file = fopen(nom_fichier, "r");
    if (!file) {
        perror("Échec de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int adresse;
    unsigned char valeur1, valeur2;
    while (fscanf(file, "%x %hhx %hhx", &adresse, &valeur1, &valeur2) == 3) {
        if (adresse >= MEMORY_SIZE - 1) {
            fprintf(stderr, "Adresse invalide : %x\n", adresse);
            fclose(file);
            exit(EXIT_FAILURE);
        }
        memory[adresse] = valeur1;
        memory[adresse + 1] = valeur2;
    }

    fclose(file);
}

void executer() {
    while (PC < MEMORY_SIZE) {
        unsigned char opcode = memory[PC++];
        unsigned char operand;

        switch (opcode) {
            case 0x00: printf("Instruction HALT rencontrée. Arrêt de l'exécution.\n"); return;
            case 0x40: A += memory[PC++]; break;
            case 0x41: A -= memory[PC++]; break;
            case 0x48: A = memory[PC++]; break;
            case 0x49: A &= memory[PC++]; break;
            case 0x4A: A |= memory[PC++]; break;
            case 0x4B: A ^= memory[PC++]; break;
            case 0x4C: A = ~A; break;
            case 0x4D: A <<= 1; break;
            case 0x4E: A >>= 1; break;
            case 0x4F: A += 1; break;
            case 0x50: A -= 1; break;
            case 0x51: A *= 2; break;
            case 0x52: A /= 2; break;
            case 0x53: A &= 0xFF; break;
            case 0x54: A |= 0xFF; break;
            default: printf("Opcode inconnu : %02x\n", opcode); return;
        }

        printf("PC : %02x, A après exécution : %02x\n", PC - 1, A);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Utilisation : %s <fichier programme>\n", argv[0]);
        return EXIT_FAILURE;
    }

    memset(memory, 0, MEMORY_SIZE);
    charger_programme(argv[1]);

    // Débogage : Afficher le contenu de la mémoire
    printf("Contenu de la mémoire avant exécution :\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("%02x ", memory[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");

    executer();
    printf("Valeur finale de A : %02x\n", A);

    return EXIT_SUCCESS;
}
