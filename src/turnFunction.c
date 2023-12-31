#include <stdio.h>

int play(int numPlayer, int tab[][3], int C, int L) {
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
  //display grid
  printf("Player %d turn\n", numPlayer);
  
  printf("Choose a card");
  getCardCoords(&x,&y, C, L);
  int firstCard = getValueAt(x,y, tab);
  printf("%d\n", firstCard);

  printf("Choose another card");
  getCardCoords(&x,&y, C, L);
  int secCard = getValueAt(x,y, tab);
  printf("%d\n", secCard);

  if(firstCard == secCard) printf("win\n");

  return 0;
}

int getValueAt(int x, int y, int tab[][3]) {
  /**
   * getValueAt - Function to get the value at a specific position in the grid.
   *
   * Parameters:
   *      - x (int): Column coordinate.
   *      - y (int): Row coordinate.
   *      - tab[][3] (int): 2D array representing the game grid.
   *
   * Return:
   *      - int: Value at the specified position in the grid.
   */
  return tab[x][y];
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
  printf("\ncolumn: ");
  while (1){
  scanf("%d", x);
  if(checkRange(*x, C)) break;
  printf("The value exceeds the table size, please enter a value between 1 and %d", C);
  printf("\ncolumn: ");
  }

  printf("row: ");
  while (1) {
  scanf("%d", y);
  if(checkRange(*y,L)) break;
  printf("The value exceeds the table size, please enter a value between 1 and %d", L);
  printf("\nrow: ");
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
