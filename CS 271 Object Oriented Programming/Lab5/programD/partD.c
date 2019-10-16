#include <stdio.h>

int main(void) {
    int temp, odd, even;

    for (int i = 1; i <= 100; i++) {
        
        scanf("%d", &temp);
        
        if (temp % 2 == 0) {
            even++;
        } else {
            odd++;
        } // end else
    } // end for
    
    printf("Even Numbers (%d): ", even);
    for (int e = 1; e <= even; e++) {
        printf("*");
    } // end even for
    
    printf("\nOdd Numbers (%d): ", odd);
    for (int o = 1; o <= odd; o++) {
        printf("*");
    } // end odd for
    
    printf("\n");
} // end main
