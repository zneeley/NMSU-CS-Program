#include "sortingfunctions.h"
#include <stdlib.h>
#include <stdio.h>
#include "helperfunctions.h"

int selectionSort ( int data[], int size ) {
    int swapCount = 0;
    
    for (int i = 0; i < size; i++){
        
        for (int x = 0; x < size; x ++){
            
            if (data[i] < data[x]) {
                swapCount++;
                swap(&data[x], &data[i]);
            }
        }
    }
    return swapCount;
}

int insertionSort ( int * const data, int size ){
    int swapCount = 0;
    int insertVal;
    
    for (int i = 0; i < size; i++) {
        insertVal = data[i];
        int moveIndex = i;
        
        while (moveIndex > 0 && data[moveIndex -1] > insertVal) {
            swap(&data[moveIndex], &data[moveIndex - 1]);
            moveIndex--;
            swapCount++;
        }
    }
    return swapCount;
}
