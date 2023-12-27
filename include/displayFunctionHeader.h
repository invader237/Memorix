#ifndef DISPLAY_H
#define DISPLAY_H

void layerDisplay(char layer[][9][2], int C, int L);
void layerEdit(int x, int y, char layer[][9][2], int table[][9], int C, int L);
void layerReset(char layer[][9][2], int C, int L);

#endif  // DISPLAY_H

