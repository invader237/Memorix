#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void strucGeneration(int *C, int *L) {
    /**
   * What the function does: Generates the values of C and L by prompting the user to choose them.
   *
   * Parameters:
   *      - C: Pointer to the variable where the value of C is to be stored.
   *      - L: Pointer to the variable where the value of L is to be stored.
   *
   * Local variables:
   *      - 
   *      - 
   *
   * Return:
   *      -
   */
    do {
        printf("Choisissez la valeur de C (5, 7, 9): ");
        scanf("%d", C);


        if (*C != 5 && *C != 7 && *C != 9) {
            printf("Veuillez taper une valeur valide pour C\n");
        }
    } while (*C != 5 && *C != 7 && *C != 9);


    do {
        printf("Choisissez la valeur de L (3, 5, 7): ");
        scanf("%d", L);


        if (*L != 3 && *L != 5 && *L != 7) {
            printf("Veuillez taper une valeur valide pour L\n");
        }
    } while (*L != 3 && *L != 5 && *L != 7);
}

void tabGeneration(int C, int L, int tab[L][C]) {
    /**
   * What the function does: Generates a table of dimensions C x L and fills it with ordered values,
   *                       then performs random exchanges to shuffle the elements of the table.
   *
   * Parameters:
   *      - C: Number of columns in the table.
   *      - L: Number of rows in the table.
   *
   * Local variables:
   *      - n: The total number of elements in the table.
   *      - count: The initial value for filling the table.
   *      - pos: The current position in the table.
   *
   * Return:
   *      - A dynamically allocated 2D array filled and shuffled.
   */
    int n = C*L;
    int count = 1;
    int pos = 0;
    srand((unsigned int)time(NULL));
    for(int l=0; l<L; l++){
      for(int c=0; c<C; c++){
        tab[l][c] = count;
        pos += 1;
        if(pos%2==0) count+=1;
        }
    }
    tab[L-1][C-1]=0;
    tabRandomization(C, L, tab);
}

void tabRandomization(int C , int L, int tab[][C]){
    
    for(int l=0; l<L; l++){
        for(int c=0; c<C; c++){
            randomSwap(C, L, c, l, tab);        
        }
    }
}

void randomSwap(int C, int L, int c, int l, int tab[][C]){
    int x = rand() % C;
    int y = rand() % L;
    int temp = tab[y][x];
    tab[y][x] = tab[l][c];
    tab[l][c] = temp;
}


void afficherTableau(int C, int L, int tab[L][C]) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

