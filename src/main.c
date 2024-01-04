#include <stdio.h>
#include <stdlib.h>
#include "../include/mainHeader.h"
#include "../include/displayFunctionHeader.h"
#include "../include/turnFunctionHeader.h"
#include "../include/tabGenerationHeader.h"

int checkValue(int n){
  if(n>=1 && n<=4) return 1;
  return 0;
}

int checkBot(char answ){
  if(answ=='y' || answ=='Y') return 1;
  else if(answ=='n' || answ=='N') return 0;
  return -1;
}


int main(){
  int C, L;
  int numberOfPlayer = 0;
  char botAnsw;
  strucGeneration(&C, &L);
  int tab[L][C];
  tabGeneration(C, L, tab);
  while(!(checkValue(numberOfPlayer))){
    printf("Combien de joueur ? (1-4): ");
    scanf("%d", &numberOfPlayer);
  }
  while(checkBot(botAnsw)==-1){
    printf("Voulez-vous jouer contre un ordinateur (y/n) : ");
    scanf("%c", &botAnsw);
  }
  while(1){
    
  }
}
