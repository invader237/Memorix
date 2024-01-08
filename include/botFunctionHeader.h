#ifndef BOT_FUNCTION_HEADER_H
#define BOT_FUNCTION_HEADER_H

int botPlay(int numPlayer, int C, int L, int tab[][C], char layer[L][C][2]);
void getRandomCardCoords(int *x, int *y, int C, int L, char layer[L][C][2]);

#endif