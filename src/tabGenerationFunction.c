#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void strucGeneration(int *C, int *L) {
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

int **tabGeneration(int C, int L) {
    int n = C * L;

    // Allocation dynamique pour le tableau
    int **tab = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        tab[i] = (int *)malloc(C * sizeof(int));
    }

    srand(time(NULL));

    // Initialisation du tableau avec des zéros
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            tab[i][j] = 0;
        }
    }

    // Remplissage initial du tableau avec les paires
    int counter = 1;
    int retour = 0;
    for (int i = 0; i < L; i++) {
        if (i > 0)
            retour = 1;
        for (int j = retour; j < C; j += 2) {
            tab[i][j] = counter;
            if ((j + 1) % C == 0) {
                tab[i + 1][0] = counter;
            } else {
                tab[i][j + 1] = counter;
            }
            counter++;
        }
    }
    tab[L - 1][C - 1] = 0;

    // Permutation aléatoire du tableau
    /*for (int i = 0; i < C; i++) {
        for (int j = 0; j < L; j++) {
            int rx = rand() % C;
            int ry = rand() % L;
            int temp = tab[j][i];
            tab[j][i] = tab[ry][rx];
            tab[ry][rx] = temp;
        }
    }*/

    return tab;
}

void afficherTableau(int **tab, int C, int L) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

/*int main() {
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
}*/

