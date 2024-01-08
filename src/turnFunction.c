#include <stdio.h>
#include <string.h>
#include "../include/turnFunctionHeader.h"
#include "../include/displayFunctionHeader.h"
#include "../include/tabGenerationHeader.h"

#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

int play(int numPlayer, int C, int L, int tab[][C], char layer[L][C][2]) {
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
  int x1,y1,x2,y2;
  printf("\nPlayer %d turn\n", numPlayer);
  

  printf("Choose a card :");
  getCardCoords(&x1,&y1, C, L);
  if(tab[y1-1][x1-1] == -1){
    while(tab[y1-1][x1-1] == -1){
      printf(RED"Invalid card, pair has already been found"RESET);
      printf("\nGive other coords :");
      getCardCoords(&x1,&y1, C, L);
    }
  }
  int firstCard = tab[y1-1][x1-1];
  layerEdit(x1, y1, C, L, layer, tab);
  printf("\033[H\033[J");
  layerDisplay(C, L, layer);
  if(firstCard == 0){
    randomSwap(C, L, x1-1, y1-1, tab);
    return -1;
  }

  printf("\nPlayer %d turn\n", numPlayer);
  printf("Choose another card :");
  getCardCoords(&x2,&y2, C, L);
  if(tab[y2-1][x2-1] == -1){
    while(tab[y2-1][x2-1] == -1){
      printf(RED"Invalid card, pair has already been found"RESET);
      printf("\nGive other coords :");
      getCardCoords(&x2,&y2, C, L);
    }
  }
  if(x1==x2 && y1 == y2){
    while(x1==x2 && y1 == y2){
      printf(RED"Invalid card, you have already selected it"RESET);
      printf("\nGive other coords :");
      getCardCoords(&x2,&y2, C, L);
    }
  }
  int secCard = tab[y2-1][x2-1];
  layerEdit(x2, y2, C, L, layer, tab);
  printf("\033[H\033[J");
  layerDisplay(C, L, layer);
  if(secCard == 0){
    randomSwap(C, L, x2-1, y2-1, tab);
    return -1;
  }

  if(firstCard == secCard){

    layer[x1-1][x1-1][0] = 'X';
    layer[y1-1][x1-1][1] = 'X';
    tab[y1-1][x1-1] = -1;

    layer[y2-1][x2-1][0] = 'X';
    layer[y2-1][x2-1][1] = 'X';
    tab[y2-1][x2-1] = -1;

    layerDisplay(C, L, layer);
    return 1;
  }
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
