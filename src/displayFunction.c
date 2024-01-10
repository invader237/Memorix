#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/displayFunctionHeader.h"

#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

void layerDisplay(int C, int L, char layer[L][C][2]) {
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
    titleDisplay();
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

void layerEdit(int x, int y, int C, int L, char layer[L][C][2], int table[][C]) {
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
    int value = table[y-1][x-1];
    // Tens digit
    layer[y-1][x-1][0] = (char)('0' + value / 10);
    // Units digit
    layer[y-1][x-1][1] = (char)('0' + value % 10);
}

void layerReset(int C, int L, char layer[L][C][2]) {
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
            if(layer[l][c][0] != 'X' && layer[l][c][1] != 'X'){
                layer[l][c][0] = '*';
                layer[l][c][1] = '*';
            }     
        }
    }
}

void titleDisplay() {
    printf("\n\n");
    printf(".----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.\n");
    printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
    printf("| | ____    ____ | || |  _________   | || | ____    ____ | || |     ____     | || |  _______     | || |     _____    | || |  ____  ____  | |\n");
    printf("| ||_   \\  /   _|| || | |_   ___  |  | || ||_   \\  /   _|| || |   .'    `.   | || | |_   __ \\    | || |    |_   _|   | || | |_  _||_  _| | |\n");
    printf("| |  |   \\/   |  | || |   | |_  \\_|  | || |  |   \\/   |  | || |  /  .--.  \\  | || |   | |__) |   | || |      | |     | || |   \\ \\  / /   | |\n");
    printf("| |  | |\\  /| |  | || |   |  _|  _   | || |  | |\\  /| |  | || |  | |    | |  | || |   |  __ /    | || |      | |     | || |    > `' <    | |\n");
    printf("| | _| |_\\/_| |_ | || |  _| |___/ |  | || | _| |_\\/_| |_ | || |  \\  `--'  /  | || |  _| |  \\ \\_  | || |     _| |_    | || |  _/ /'`\\ \\_  | |\n");
    printf("| ||_____||_____|| || | |_________|  | || ||_____||_____|| || |   `.____.'   | || | |____| |___| | || |    |_____|   | || | |____||____| | |\n");
    printf("| |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
    printf("\n                                                                                                                                    v1.0");
    printf("\n\n");
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
