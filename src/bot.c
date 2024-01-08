#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/turnFunctionHeader.h"
#include "../include/displayFunctionHeader.h"
#include "../include/tabGenerationHeader.h"
#include "../include/botFunctionHeader.h"

int botPlay(int numPlayer, int C, int L, int tab[][C], char layer[L][C][2]) {
    /**
     * botPlay - Function to simulate a turn for a bot player in a memory matching game.
     *
     * This function randomly selects two cards for the bot player and checks if they match.
     *
     * Parameters:
     *      - numPlayer (int): Player number.
     *      - tab[][C] (int): 2D array representing the game grid.
     *      - C (int): Number of columns in the grid.
     *      - L (int): Number of rows in the grid.
     *      - layer[L][C][2] (char): 3D array representing the display layer.
     *
     * Return:
     *      - void
     */
    int x1, y1, x2, y2;

    // Bot randomly selects two cards
    getRandomCardCoords(&x1, &y1, C, L, layer);
    getRandomCardCoords(&x2, &y2, C, L, layer);

    // Ensure that the bot doesn't select the same card twice
    while (x1 == x2 && y1 == y2) {
        getRandomCardCoords(&x2, &y2, C, L, layer);
    }

    printf("\nBot Player %d turn\n", numPlayer);

    printf("Selected card 1: (%d, %d)\n", x1, y1);
    int firstCard = tab[y1-1][x1-1];
    layerEdit(x1, y1, C, L, layer, tab);
    sleep(1);
    printf("\033[H\033[J");
    layerDisplay(C, L, layer);
    if(firstCard == 0){
        randomSwap(C, L, x1-1, y1-1, tab);
        return -1;
    }

    printf("\nBot Player %d turn\n", numPlayer);

    printf("Selected card 2: (%d, %d)\n", x2, y2);
    int secCard = tab[y2-1][x2-1];
    layerEdit(x2, y2, C, L, layer, tab);
    sleep(1);
    printf("\033[H\033[J");
    layerDisplay(C, L, layer);
    if(secCard == 0){
        randomSwap(C, L, x2-1, y2-1, tab);
        return -1;
    }

    if (firstCard == secCard) {
        
        printf("\033[H\033[J");
        layer[x1 - 1][x1 - 1][0] = 'X';
        layer[y1 - 1][x1 - 1][1] = 'X';
        tab[y1 - 1][x1 - 1] = -1;

        layer[x2 - 1][x2 - 1][0] = 'X';
        layer[y2 - 1][x2 - 1][1] = 'X';
        tab[y2 - 1][x2 - 1] = -1;

        layerDisplay(C, L, layer);
        printf("\nBot Player %d found a match!\n", numPlayer);
        return 1;
    } else {
        printf("\nBot Player %d did not find a match.\n", numPlayer);
        return 0;
    }
}

void getRandomCardCoords(int *x, int *y, int C, int L, char layer[L][C][2]) {
    /**
     * getRandomCardCoords - Function to get random valid coordinates for card selection.
     *
     * Parameters:
     *      - x (int*): Pointer to the variable to store the column coordinate.
     *      - y (int*): Pointer to the variable to store the row coordinate.
     *      - C (int): Number of columns in the grid.
     *      - L (int): Number of rows in the grid.
     *      - layer[L][C][2] (char): 3D array representing the display layer.
     *
     * Return:
     *      - void
     */
    srand((unsigned int)time(NULL));
    do {
        *x = rand() % C + 1;
        *y = rand() % L + 1;
    } while (layer[*y - 1][*x - 1][1] == 'X'); // Ensure the card hasn't been already matched
}

