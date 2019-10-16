#include "helperfunctions.h"
#include <stdlib.h>
#include <stdio.h>

void neatPrint( int  data[], int size, int numPerLine, int fieldSize ) {
    int newLine = 0;
    
    for (int i = 0; i < size; i++) {
        printf("%*d", fieldSize, data[i]);
        newLine ++;
        
        if (newLine == numPerLine) {
            printf("\n");
            newLine = 0;
        }
    }
}

void fillArray( int data[], int size, int min, int max ) {
    
    for (int i = 0; i < size; i++ ){
        
        data[i] = rand() % max + min;
        
    }
}

void swap(int * num1, int * num2) {
    int temp;
    
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    
}
