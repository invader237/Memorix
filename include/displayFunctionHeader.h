#ifndef DISPLAY_H
#define DISPLAY_H

void layerDisplay(int C, int L, char layer[L][C][2]);
void layerEdit(int x, int y, int C, int L, char layer[L][C][2], int table[][C]);
void layerReset(int C, int L, char layer[L][C][2]);

#endif  // DISPLAY_H

