#include <stdio.h>
#include <stdlib.h>

// Fonction pour filtrer certains caractères d'un fichier d'entrée et écrire le résultat dans un fichier de sortie
void filter_chars(const char *input_file, const char *output_file) {
    // Ouvre le fichier d'entrée en mode lecture
    FILE *infile = fopen(input_file, "r");
    // Ouvre le fichier de sortie en mode écriture
    FILE *outfile = fopen(output_file, "w");
    
    // Vérifie si les fichiers ont été ouverts correctement
    if (infile == NULL || outfile == NULL) {
        perror("Error opening file"); // Affiche un message d'erreur si un fichier ne peut pas être ouvert
        exit(EXIT_FAILURE); // Quitte le programme avec un code d'erreur
    }

    char ch;
    // Lit chaque caractère du fichier d'entrée jusqu'à la fin du fichier (EOF)
    while ((ch = fgetc(infile)) != EOF) {
        // Si le caractère n'est pas une tabulation, ni '<', ni '>', il est écrit dans le fichier de sortie
        if (ch != '\t' && ch != '<' && ch != '>') {
            fputc(ch, outfile);
        }
    }

    // Ferme les fichiers d'entrée et de sortie
    fclose(infile);
    fclose(outfile);
}

int main() {
    // Appelle la fonction filter_chars avec "index.html" comme fichier d'entrée et "output.txt" comme fichier de sortie
    filter_chars("index.html", "output.txt");
    // Affiche un message indiquant que le filtrage est terminé
    printf("Filtrage terminé. Vérifier le fichier output.txt\n");
    return 0;
}
