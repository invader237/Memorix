#include <stdio.h>

int play(int numPlayer, int tab[][3], int C, int L) {
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
  return tab[x][y];
}

void getCardCoords(int *x, int *y, int C, int L) {
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
