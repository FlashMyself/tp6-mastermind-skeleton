#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"

void rules() {
    printf("Mastermind\n");
    printf("Devinez 4 chiffres entre 1 et 6\n");
    printf("o : bon chiffre bonne place\n");
    printf("x : bon chiffre mauvaise place\n");
    printf("- : absent\n");
    printf("%d essais\n\n", MAX_ATTEMPTS);
}

void init_grid(char *grid[]) {
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        grid[i] = malloc(20 * sizeof(char));
        strcpy(grid[i], "- - - - | - - - -");
    }
}

void free_grid(char *grid[]) {
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        free(grid[i]);
    }
}

void update_grid(char *grid[], int attempt, int propos[], char result[]) {
    for (int i = 0; i < CODE_SIZE; i++) {
        grid[attempt][2 * i] = '0' + propos[i];
        grid[attempt][10 + 2 * i] = result[i];
    }
}

void display_grid(char *grid[]) {
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("%s\n", grid[i]);
    }
}