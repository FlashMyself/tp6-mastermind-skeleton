#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"

void random_comb(int comb[]) {
    for (int i = 0; i < CODE_SIZE; i++)
        comb[i] = rand() % 6 + 1;
}

void display_comb(int comb[]) {
    for (int i = 0; i < CODE_SIZE; i++)
        printf("%d ", comb[i]);
    printf("\n");
}

void read_comb(int comb[]) {
    for (int i = 0; i < CODE_SIZE; i++) {
        scanf("%d", &comb[i]);

        if (comb[i] < 1 || comb[i] > 6) {
            printf("Valeur invalide (1-6). Recommence : ");
            i--;
        }
    }
}

int present(int comb[], int number) {
    for (int i = 0; i < CODE_SIZE; i++) {
        if (comb[i] == number)
            return 1;
    }
    return 0;
}

void check_result(int comb[], int propos[], char result[]) {
    for (int i = 0; i < CODE_SIZE; i++) {
        if (propos[i] == comb[i]) {
            result[i] = 'o';
        } else if (present(comb, propos[i])) {
            result[i] = 'x';
        } else {
            result[i] = '-';
        }
    }
}