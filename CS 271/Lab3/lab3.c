#include <stdio.h>
#include <stdlib.h>
#include "helperfunctions.h"
#include "sortingfunctions.h"
#include <time.h>
#define ARRAYSIZE 20

int main (void) {
    
    srand(time(NULL));
    
    // dynamically allocate memory space for an array
    int * arrayPtr = (int *) malloc (ARRAYSIZE * sizeof(int));
    // from here on, you can use arrayPtr anywhere you would use the
    // name of an array
    
    // fill the array with random integers
    fillArray(arrayPtr, ARRAYSIZE, 0, 100);
    
    // print the array, 10 elements per line
    printf("Random Array with a size of %d. \n", ARRAYSIZE);
    neatPrint(arrayPtr, ARRAYSIZE, 10, 3);
    printf("\n");
    
    // sort the array using selection sort
    printf("Selection Sort swap count: %d\n", selectionSort(arrayPtr, ARRAYSIZE));
     
    // print the array, 10 elements per line
    neatPrint(arrayPtr, ARRAYSIZE, 10, 3);
    printf("\n");
    
    
    // fill the array again with random integers
    fillArray(arrayPtr, ARRAYSIZE, 0, 100);
    
    // print the array
    printf("Random Array with a size of %d. \n", ARRAYSIZE);
    neatPrint(arrayPtr, ARRAYSIZE, 10, 3);
    printf("\n");
    
    // sort with insertion sort
    printf("Insertion Sort swap count: %d\n",insertionSort(arrayPtr, ARRAYSIZE));
    
    // print the array
    neatPrint(arrayPtr, ARRAYSIZE, 10, 3);
    
}
