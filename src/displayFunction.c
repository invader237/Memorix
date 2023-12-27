#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CYAN     "\x1b[36m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

void layerDisplay(char layer[][9][2], int C, int L);
void layerEdit(int x, int y, char layer[][9][2], int table[][9], int C, int L);
void layerReset(char layer[][9][2], int C, int L);

void layerDisplay(char layer[][9][2], int C, int L) {
    for (int i = 0; i < C; i++) {
        if (i == 0) printf("   ");
        printf("   %d ", i + 1);
    }
    printf("\n");
    for (int c = 0; c < C; c++) {
        if (c == 0) printf("   ");
        printf("+====");
    }
    printf("+\n");
    for (int l = 0; l < L; l++) {
        for (int c = -1; c < C; c++) {
            if (c == -1) printf(" %d ", l + 1);
            else if (layer[l][c][1]!='*') printf("|" YELLOW " %c%c " RESET, layer[l][c][0], layer[l][c][1]);
            else printf("| %c%c ", layer[l][c][0], layer[l][c][1]);
        }

        printf("|\n");
        for (int c = 0; c < C; c++) {
            if (c == 0) printf("   ");
            printf("+----");
        }
        printf("+\n");
    }
}

void layerEdit(int x, int y, char layer[][9][2], int table[][9], int C, int L) {
    int value = table[y - 1][x - 1];
    // Chiffre des dizaines
    layer[y - 1][x - 1][0] = (char)('0' + value / 10);

    // Chiffre des unités
    layer[y - 1][x - 1][1] = (char)('0' + value % 10);
}

void layerReset(char layer[][9][2], int C, int L) {
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            layer[l][c][0] = '*';
            layer[l][c][1] = '*';
        }
    }
}

int main() {
    // Définir la taille des tableaux
    int C = 5;
    int L = 5;

    int table[][9] = {
        {0, 1, 1, 2, 2},
        {3, 3, 4, 4, 5},
        {5, 6, 6, 7, 7},
        {8, 8, 9, 9, 10},
        {10, 11, 11, 12, 12}
    };
    char layer[][9][2] = {
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}},
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}},
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}},
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}},
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}}
    };

    int x = 5;
    int y = 5;

    layerDisplay(layer, C, L);
    layerEdit(x, y, layer, table, C, L);
    layerDisplay(layer, C, L);
    layerReset(layer, C, L);
    layerDisplay(layer, C, L);

    return 0;
}

