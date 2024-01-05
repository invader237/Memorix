#include <stdio.h>
#include "../include/turnFunctionHeader.h"
#include "../include/displayFunctionHeader.h"

int play(int numPlayer, int C, int L, int tab[][C], int layer[][C][2]) {
  /**
   * play - Function to simulate a turn for a player in a memory matching game.
   *
   * This function displays the grid, prompts the player to choose two cards, and checks if the chosen cards match.
   *
   * Parameters:
   *      - numPlayer (int): Player number.
   *      - tab[][3] (int): 2D array representing the game grid.
   *      - C (int): Number of columns in the grid.
   *      - L (int): Number of rows in the grid.
   *
   * Local variables:
   *      - x, y (int): Coordinates for card selection.
   *      - firstCard, secCard (int): Values of the selected cards.
   *
   * Return:
   *      - int: Always returns 0.
   */
  int x,y;
  printf("Player %d turn\n", numPlayer);
  
  printf("Choose a card");
  getCardCoords(&x,&y, C, L);
  int firstCard = tab[y-1][x-1];
  layerEdit(x, y, layer, tab, C, L);
  layerDisplay(layer, C, L);

  printf("Choose another card");
  getCardCoords(&x,&y, C, L);
  int secCard = tab[y-1][x-1];
  layerEdit(x, y, layer, tab, C, L);
  layerDisplay(layer, C, L);

  if(firstCard == secCard) return 1;

  return 0;
}

void getCardCoords(int *x, int *y, int C, int L) {
  /**
   * getCardCoords - Function to get the coordinates of a card selected by the player.
   *
   * Parameters:
   *      - x (int*): Pointer to the variable to store the column coordinate.
   *      - y (int*): Pointer to the variable to store the row coordinate.
   *      - C (int): Number of columns in the grid.
   *      - L (int): Number of rows in the grid.
   *
   * Return:
   *      - void
   */
  while (1) {
    printf("\ncolumn: ");
    scanf("%d", x);
    if (checkRange(*x, C)) break;
    printf("The value exceeds the table size, please enter a value between 1 and %d\n", C);
  }

  while (1) {
    printf("row: ");
    scanf("%d", y);
    if (checkRange(*y, L)) break;
    printf("The value exceeds the table size, please enter a value between 1 and %d\n", L);
  }
  printf("\n");
}

int checkRange(int number, int maxRange) {
  /**
   * checkRange - Function to check if a number is within a specified range.
   *
   * Parameters:
   *      - number (int): The number to be checked.
   *      - maxRange (int): The maximum value allowed in the range.
   *
   * Return:
   *      - int: 1 if the number is within the range, 0 otherwise.
   */
  if (number<=maxRange && number>=0)return 1; //change the min to number >0 when implementing the CLI
  return 0;
}

/*
int main() {
  int x, y;
  int tab[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  play(1, tab, 3, 3);

  return 0;
}
*/
