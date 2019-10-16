#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
    int randInput, randNum;
    
    srand(time(NULL));
    
    printf("Input a number: ");
    scanf("%d", &randInput);
    
    randNum = rand() % randInput + 1;
    
    printf("Here is a random number between 1 and %d -----> %d\n", randInput, randNum);
}
