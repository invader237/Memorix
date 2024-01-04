#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CYAN    "\x1b[36m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

void layerDisplay(char layer[][9][2], int C, int L) {
    /**
      * Displays the formatted layer line by line.
      *
      * Parameters:
      *      - layer (char[][][2]): 3D array representing the layer to be displayed.
      *      - C (int): Number of columns in the layer.
      *      - L (int): Number of rows in the layer.
      * 
      * Local variables:
      *      - i, c, l (int): Loop variables.
      * 
      * Return:
      *      - void
      */
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
            else if (layer[l][c][1] != '*') printf("|" YELLOW " %c%c " RESET, layer[l][c][0], layer[l][c][1]);
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
    /**
     * Edits the specified position in the layer based on the value from the table.
     *
     * Parameters:
     *       - x, y (int): Coordinates of the position to be edited (1-based).
     *      - layer (char[][][2]): 3D array representing the layer.
     *      - table (int[][]): 2D array containing values to be placed in the layer.
     *      - C (int): Number of columns in the layer.
     *      - L (int): Number of rows in the layer.
     * 
     * Local variables:
     *      - value (int): Value retrieved from the table.
     * 
     * Return:
     *      - void
     */
    int value = table[y - 1][x - 1];
    // Tens digit
    layer[y - 1][x - 1][0] = (char)('0' + value / 10);

    // Units digit
    layer[y - 1][x - 1][1] = (char)('0' + value % 10);
}

void layerReset(char layer[][9][2], int C, int L) {
    /**
     * Resets all elements in the layer to '*'.
     *
     * Parameters:
     *      - layer (char[][][2]): 3D array representing the layer to be reset.
     *      - C (int): Number of columns in the layer.
     *      - L (int): Number of rows in the layer.
     * 
     * Local variables:
     *      - l, c (int): Loop variables.
     * 
     * Return:
     *      - void
     */
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            layer[l][c][0] = '*';
            layer[l][c][1] = '*';
        }
    }
}

/*
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
*/
