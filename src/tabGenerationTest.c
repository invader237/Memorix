#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void strucGeneration(int *C, int *L);
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
void tabGeneration(int C, int L, int tab[L][C]);
/**
   * What the function does: Generates and shuffles a 2D array of dimensions C x L.
   *
   * Parameters:
   *      - C: Number of columns in the 2D array.
   *      - L: Number of rows in the 2D array.
   *      - tab: 2D array to be generated and shuffled.
   *
   * Local variables:
   *      -
   *      -
   *
   * Return:
   *      -
   */
void afficherTableau(int C, int L, int tab[L][C]);
/**
   * What the function does: Displays the contents of a 2D array.
   *
   * Parameters:
   *      - C: Number of columns in the 2D array.
   *      - L: Number of rows in the 2D array.
   *      - tab: 2D array to be displayed.
   *
   * Local variables:
   *      -
   *      -
   *
   * Return:
   *      -
   */

int testStrucGeneration();
/**
   * What the function does: Tests the strucGeneration function by displaying the generated values of C and L.
   *
   * Parameters:
   *      -
   *
   * Local variables:
   *      - C: Variable to store the generated value of C.
   *      - L: Variable to store the generated value of L.
   *
   * Return:
   *      - 0 on successful execution.
   */


int main() {
    /**
   * What the program does: Executes the main functionality of the program.
   *
   * Parameters:
   *      -
   *
   * Local variables:
   *      - C: Variable to store the generated value of C.
   *      - L: Variable to store the generated value of L.
   *      - tab: 2D array to be generated and displayed.
   *
   * Return:
   *      - 0 on successful execution.
   */
    int C, L;

    // Call strucGeneration to get values for C and L
    strucGeneration(&C, &L);

    // Declare a 2D array with dimensions C x L
    int tab[L][C];

    // Generate and shuffle the 2D array
    tabGeneration(C, L, tab);

    // Display the contents of the 2D array
    afficherTableau(C, L, tab);

    return 0;
}
