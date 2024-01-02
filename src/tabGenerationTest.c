#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/tabGenerationFunctionHeader.h"


void strucGeneration(int *C, int *L);
int **tabGeneration(int C, int L);
void afficherTableau(int **tab, int C, int L);

int testStrucGeneration(){
    int C,L;
    strucGeneration(&C,&L);
    printf("C=%d et L=%d \n",C,L);
    return 0;
}

int main() {
    int C, L;
    strucGeneration(&C, &L);
    int **tab = tabGeneration(C, L);
    afficherTableau(tab, C, L);

    // Libération de la mémoire allouée pour le tableau
    for (int i = 0; i < L; i++) {
        free(tab[i]);
    }
    free(tab);

    return 0;
}