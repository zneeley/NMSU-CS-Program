// Header Comments NEED TO INPUT INTO THE PROGRAM
#include "lab2functions.h"
#include <ctype.h>
#include <stdio.h>

void printCharArray (char letterArray[], int arraySize) {
    int newLine = 0;
    
    for (int i = 0; i <= arraySize; i++) {
        printf ("%c ", letterArray[i]);
        newLine++;
        
        if (newLine % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int countLetters (char letterArray[], int arraySize) {
    int numberOfLetters = 0;
    
    for (int i = 0; i<= arraySize; i++) {
        if (isalpha(letterArray[i])) {
            numberOfLetters++;
        }
    }
    
    return numberOfLetters;
}

int numMatches (char letterArray1[], char letterArray2[], int arraySize) {
    int matchingLetters = 0;
    
    for (int i = 0; i<= arraySize; i++) {
        if (letterArray1[i] == letterArray2[i]) {
            matchingLetters++;
        }
    }
    
    return matchingLetters;
}

void capitalize (char letterArray[], int arraySize) {
    
    for (int i = 0; i <= arraySize; i++) {
        if (islower(letterArray[i])) {
           letterArray[i] = toupper(letterArray[i]);
        }
    }
    
}
