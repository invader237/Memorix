#ifndef TURN_FUNCTION_H
#define TURN_FUNCTION_H

int play(int numPlayer, int tab[][3], int C, int L);
int getValueAt(int x, int y, int tab[][3]);
void getCardCoords(int *x, int *y, int C, int L);
int checkRange(int number, int maxRange);

#endif
