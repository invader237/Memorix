#include <stdio.h>
#include <stdlib.h>
#include "../include/mainHeader.h"
#include "../include/displayFunctionHeader.h"
#include "../include/turnFunctionHeader.h"
#include "../include/tabGenerationHeader.h"

struct Player {
    int playerNumber;
    int score;
};

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
  struct Player players[4] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
  char botAnsw;
  char layer[7][9][2];

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 9; j++) {
        layer[i][j][0] = '*';
        layer[i][j][1] = '*';
    }
  }
                        
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
      players[playerNumber - 1].score += 1;
    }
    else if(turnScore == 0){
      printf("You haven't found a match\n");
      playerNumber += 1;
      if(playerNumber > numberOfPlayer) playerNumber = 1;
    }
    else if(turnScore == -1){
      printf("You have found the joker\n you lost a point\n");
      players[playerNumber - 1].score -= 1;
    }
    printf("Your score is now : %d\n", players[playerNumber - 1].score);
  }
}
