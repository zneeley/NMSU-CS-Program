#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define ARRAYSIZE 10

void shiftLeft (int *firstPtr, int *lastPtr) {
    int temp = *firstPtr;
    int *nextPtr = firstPtr + 1;
    int *currentPtr = firstPtr;
    
    for (int i = 0; i < ARRAYSIZE; i++) {
        *currentPtr = *nextPtr;
        currentPtr++;
        nextPtr++;
    }
    
    *lastPtr = temp;

}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d    ", array[i]);
    }
    
    printf("\n");
}

int main(void) {
    int array[ARRAYSIZE], max = 100, min = 0;
    int *arrayPtr = (int *) malloc (ARRAYSIZE * sizeof(int));
    
    srand(time(NULL));
    
    for (int i = 0; i < ARRAYSIZE; i++) {
        array[i] = rand() % max + min;
    }
    
    printArray(array, ARRAYSIZE);
    
    shiftLeft(&array[0], &array[ARRAYSIZE - 1]);
    
    printArray(array, ARRAYSIZE);
}
