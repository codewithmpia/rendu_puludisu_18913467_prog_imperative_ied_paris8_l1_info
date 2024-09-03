#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAMES_LENGTH 50
#define MAX_STOPLIST 100

int is_in_stoplist(char *word, char stoplist[][MAX_NAMES_LENGTH], int stoplist_count) {
    for (int i = 0; i < stoplist_count; i++) {
        if (strcmp(word, stoplist[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        printf("Une erreur s'est produite lors de l'ouverture du fichier data.txt.\n");
        return 1;
    }

    char names[MAX_NAMES][MAX_NAMES_LENGTH];
    int count = 0;

    while (count < MAX_NAMES && fscanf(file, "%s", names[count]) != EOF) {
        count++;
    }
    fclose(file);

    FILE *stoplist_file = fopen("stoplist.txt", "r");
    if (!stoplist_file) {
        printf("Une erreur s'est produite lors de l'ouverture du fichier stoplist.txt.\n");
        return 1;
    }

    char stoplist[MAX_STOPLIST][MAX_NAMES_LENGTH];
    int stoplist_count = 0;

    while (stoplist_count < MAX_STOPLIST && fscanf(stoplist_file, "%s", stoplist[stoplist_count]) != EOF) {
        stoplist_count++;
    }
    fclose(stoplist_file);

    for (int i = 0; i < count; i++) {
        if (!is_in_stoplist(names[i], stoplist, stoplist_count)) {
            printf("%s\n", names[i]);
        }
    }
    return 0;
}
