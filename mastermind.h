#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define CODE_SIZE 3
#define NB_COLORS 6
#define SIZE_COMB 3
#define MAX_ATTEMPTS 8

void display_comb(int comb[]);
void read_comb(int arr[]);
void random_comb(int comb[]);
int well_placed(int comb[], int propos[]);
int present(int comb[], int number);
void check_result(int comb[], int propos[], char result[]);
void init_grid(char * grid[]);
void free_grid(char * grid[]);
void update_grid(char * grid[], int attemp, int propos[], char result[]);

#endif // MASTERMIND_H