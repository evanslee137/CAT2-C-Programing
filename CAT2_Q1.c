/*
name:EVANS KOMAREN SEKUT
reg no:CT101/G/22798/24
description:2Darray
*/

#include <stdio.h>

int main() {
    
    int scores[2][2] = { {65, 92}, {84, 72} };
    int scores2[2][2] = { {35, 70}, {59, 67} };

   
    printf("Scores Array 1:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }

    printf("Scores Array 2:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", scores2[i][j]);
        }
        printf("\n");
    }

    return 0;

}
