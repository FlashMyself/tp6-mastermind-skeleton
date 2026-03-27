17#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "mastermind.h"

int main() {
    srand(time(NULL));

    char *grid[MAX_ATTEMPTS];
    int secret[CODE_SIZE];
    int guess[CODE_SIZE];
    char result[CODE_SIZE];

    rules();
    init_grid(grid);
    random_comb(secret);

    printf("Secret: ");
    display_comb(secret);
    printf("\n");

    for (int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
        printf("Essai %d: ", attempt + 1);
        read_comb(guess);

        check_result(secret, guess, result);
        update_grid(grid, attempt, guess, result);

        display_grid(grid);
        printf("\n");

        int win = 1;
        for (int i = 0; i < CODE_SIZE; i++) {
            if (result[i] != 'o') {
                win = 0;
                break;
            }
        }

        if (win) {
            printf("Bravo ! Tu as trouvé la combinaison !\n");
            free_grid(grid);
            return 0;
        }
    }

    printf("Perdu ! La combinaison était : ");
    display_comb(secret);

    free_grid(grid);
    return 0;
}