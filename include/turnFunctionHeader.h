#ifndef TURN_FUNCTION_H
#define TURN_FUNCTION_H

int play(int numPlayer, int C, int L, int tab[][C], int layer[][C][2]);
void getCardCoords(int *x, int *y, int C, int L);
int checkRange(int number, int maxRange);

#endif
