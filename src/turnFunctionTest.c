#include <stdio.h>
#include "../include/turnFunctionHeader.h"

int testGetCardCoords(){
  int x,y;
  int C = 5;
  int L = 3;
  getCardCoords(&x,&y,C,L);
  printf("column = %d row = %d \n", x,y);
  return 0;
}

int testCheckRange(){
  int number = 3;
  int C = 4;
  printf("1 if 0<=number<=C: %d. Number = %d, C=%d\n", checkRange(number, C), number, C);
  number = 4;
  C = 3;
  printf("1 if 0<=number<=C: %d. Number = %d, C=%d\n", checkRange(number, C), number, C);
  return 0;
}

int testPlay(){
  int numPlayer = 1;
  int C = 5;
  int L = 3;
  int tab[3][5] = {{1,2,3,4,5},
                  {6,7,8,9,10},
                  {11,12,13,14,15}};
  
  printf("\nstart of play function test\n");
  play(numPlayer, C, L, tab);
  return 1;
}

int main() {
  testGetCardCoords();
  testCheckRange();
  testPlay();

  return 0;
}
