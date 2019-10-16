// Header Comments NEED TO INPUT INTO THE PROGRAM
#include "lab2functions.h"
#include <stdio.h>

char letterArray1[20] = {'a', 'H', '1', '.', 'Z','!', 'H', 'g', 'w', 'Z','s', 'J', '1', 'T', 'Q','!', 'Z', 'a', 'c', 'h'};
char letterArray2[20] = {'a', 'H', 'K', 'k', 'r','a', '2', 's', 'o', ';','s', 'H', 'K', 'k', 'r','g', '2', '5', 'i', '['};

int main(void) {
    
    // Print letterArray1
    printf("Printing letterArray1:\n");
    printCharArray(letterArray1, 20);
    
    // Print letterArray2
    printf("Printing letterArray2:\n");
    printCharArray(letterArray1, 20);
    
    // Count the number of letters in letterArray1
    printf("Counting letters in letterArray1: ");
    printf("%d \n",countLetters(letterArray1, 20));
    
    // Count the number of letters in letterArray2
    printf("Counting letters in letterArray2: ");
    printf("%d \n",countLetters(letterArray2, 20));
    
    // Will look see if anything from letterArray1 and letterArray2
    // match if so will return the number of how much do.
    printf("Checking letterArray1 and letterArray2 for matching letters.\n");
    printf("Amount Matching: %d \n",numMatches(letterArray1, letterArray2, 20));
    
    // Will convert all the lowercase to uppercase in letterArray1 
    // then will use printCharArray to show it worked.
    printf("Convert all lowercase to uppercase letters in letterArray1 the use printCharArray.\n");
    capitalize(letterArray1,20);
    printCharArray(letterArray1, 20);
    
    // Will convert all the lowercase to uppercase in letterArray2 
    // then will use printCharArray to show it worked.
    printf("Convert all lowercase to uppercase letters in letterArray2 the use printCharArray.\n");
    capitalize(letterArray2,20);
    printCharArray(letterArray2, 20);
}
