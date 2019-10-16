#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float radius = 0, height = 0;
    float volume = 0, surfaceArea = 0;
    double pi = 3.14159;
    
    printf("Please input the radius of a cylinder: ");
    scanf("%f", &radius);
    
    printf("Please input the height of a cylinder: ");
    scanf("%f", &height);
    
    surfaceArea = 2 * pi * (radius * radius) + 2 * pi * radius * height;
    
    volume = pi * (radius * radius) * height;
    
    printf("The surface area of the cylinder is: %.3lf", surfaceArea);
    
    printf("\nThe volume of the cylinder is: %.3lf\n", volume);
}
