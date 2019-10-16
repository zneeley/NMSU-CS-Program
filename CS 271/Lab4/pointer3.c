//
//
//    HEADER NEEDED
//

// Prototyes
int input(int *a, int *b, int *c);

int sumsort(int *a, int *b, int *c);

#include <stdio.h> 
#include <ctype.h>

// Main
int main(void) {
    
    int input1, input2, input3, count = 0, sumVal;
    
     while (!feof(stdin)) {
        
        count = input(&input1, &input2, &input3);
        
        if (feof(stdin)) {
            printf("End of input reached \n");
            
        } else {
            printf("The inputted values are: %d %d %d \n", input1, input2, input3);
            
            sumVal = sumsort(&input1, &input2, &input3);
            
            printf("The sorted values are: %d %d %d \n", input1, input2, input3);
            printf("The sum of the 3 values is: %d \n", sumVal);
            
        }
        
     }
}

// Functions
int input(int *a, int *b, int *c) {
    
    printf("Input 3 numbers: \n");
    
    return scanf("%d %d %d",a ,b ,c);
}

int sumsort(int *a, int *b, int *c) {
    
    int temp, total;

    if (*b > *a) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    
    if (*c > *b) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    
    if (*b > *a) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    return total = *a + *b + *c;
    
}
