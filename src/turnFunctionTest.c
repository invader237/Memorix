#include <stdio.h>
#include "../include/turnFunctionHeader.h"

int testGetValueAt() {
  int tab[][3] = {{1,2,3},
              {4,5,6},
              {7,8,9}};
  int x,y;
  for(x=0; x<3; x++ ){
    for(y=0;y<3; y++ ){
      printf("%d\n",getValueAt(x,y, tab));
    }
  }
  return 0;
}

int testGetCardCoords(){
  int x,y;
  int C = 5;
  int L = 3;
  getCardCoords(&x,&y,C,L);
  printf("column = %d row = %d ", x,y);
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
  int tab[][3] = {{1,2,3},
                  {4,5,6},
                  {7,8,9}};
  int C = 5;
  int L = 3;
  printf("\nstart of play function test\n");
  play(numPlayer, tab, C, L);
  return 1;
}

int main() {
  testGetValueAt();
  testGetCardCoords();
  testCheckRange();
  testPlay();

  return 0;
}
