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
  int turnScore = 0;
  int playerNumber = 1;
  char botAnsw;
  char layer[][9][2] = {
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}},
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}},
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}},
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}},
        {{'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}, {'*', '*'}}
    };
  
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
    layerDisplay(layer, C, L);
    turnScore = play(playerNumber, C, L, tab, layer);
    layerReset(layer, C, L);
    if(turnScore == 1){
      printf("\nYou have won 1 point, you can play again\n");
      //increment player score
    }
    else if(turnScore == 0){
      printf("You haven't found a match\n");
      playerNumber += 1;
      if(playerNumber > numberOfPlayer) playerNumber = 1;
    }
  }
}
