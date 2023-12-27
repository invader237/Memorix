#include <stdio.h>
#include "../include/displayFunctionHeader.h"
#define C_display 5
#define L_display 5
#define x_edit 5
#define y_edit 5


//========================================================================
char test_layer_display[5][9][2] = {
        {{'1', '2'}, {'3', '4'}, {'5', '6'}, {'7', '8'}, {'9', '0'}},
        {{'0', '1'}, {'2', '3'}, {'4', '5'}, {'6', '7'}, {'8', '9'}},
        {{'9', '8'}, {'7', '6'}, {'5', '4'}, {'3', '2'}, {'1', '0'}},
        {{'0', '0'}, {'1', '1'}, {'2', '2'}, {'3', '3'}, {'4', '4'}},
        {{'5', '5'}, {'*', '*'}, {'7', '7'}, {'8', '8'}, {'9', '9'}}
    };

int test_table_edit[5][9] = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15, 16, 17},
        {18, 19, 20, 21, 22, 23, 24, 25, 26},
        {27, 28, 29, 30, 31, 32, 33, 34, 35},
        {36, 37, 38, 39, 40, 41, 42, 43, 44}
    };

//========================================================================

int layerDisplayTest(){
    printf("Test de layerDisplay :\n");
    layerDisplay(test_layer_display, C_display, L_display);
    printf("\n");
    return 1;
}

int layerEditTest(){
    printf("Test de layerEdit :\n");
    
    layerEdit(x_edit, y_edit, test_layer_display, test_table_edit, C_display, L_display);
    layerDisplay(test_layer_display, C_display, L_display);
    printf("\n");
    return 1;
}

int layerResetTest(){
    printf("Test de layerReset :\n");
    layerReset(test_layer_display, C_display, L_display);
    layerDisplay(test_layer_display, C_display, L_display);
    return 1;
}

int main() {    
    layerDisplayTest();
    layerEditTest();
    layerResetTest();
    return 0;
}
