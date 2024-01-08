#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/mainHeader.h"
#include "../include/displayFunctionHeader.h"
#include "../include/turnFunctionHeader.h"
#include "../include/tabGenerationHeader.h"

#define CYAN    "\x1b[36m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RED     "\x1b[31m"
#define ORANGE  "\x1b[38;5;208m"
#define RESET   "\x1b[0m"


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
  int matchCounter = 0;
  int maxMatch;
  int numberOfPlayer = 0;
  int turnScore = 0;
  int playerNumber = 1;
  struct Player players[4] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
  char botAnsw;
  srand((unsigned int)time(NULL));

  strucGeneration(&C, &L);
  maxMatch = (C*L-1)/2;

  char layer[L][C][2];
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < C; j++) {
        layer[i][j][0] = '*';
        layer[i][j][1] = '*';
    }
  }

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
  printf("\033[H\033[J");
  while(matchCounter!=maxMatch){

    layerDisplay(C, L, layer);
    turnScore = play(playerNumber, C, L, tab, layer);
    layerReset(C, L, layer);
    if(turnScore == 1){
      printf(GREEN"\nYou have won 1 point, you can play again\n"RESET);
      players[playerNumber - 1].score += 1;
    }
    else if(turnScore == 0){
      printf(ORANGE"You haven't found a match\n"RESET);
      matchCounter+=1;
      playerNumber += 1;
      if(playerNumber > numberOfPlayer) playerNumber = 1;
    }
    else if(turnScore == -1){
      printf(RED"You have found the joker.\nYou lost a point\n"RESET);
      playerNumber += 1;
      if(playerNumber > numberOfPlayer) playerNumber = 1;

      players[playerNumber - 1].score -= 1;
    }
    printf("Your score is now : %d\n", players[playerNumber - 1].score);
    sleep(4);
    printf("\033[H\033[J");
  }
  printf("partie terminer");
}
