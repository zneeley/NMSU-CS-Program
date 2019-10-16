#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int annualSalary = 0, numYears = 0;
    double retirementCalc = 0;
    
    printf("Input the annual salary: ");
    scanf("%d", &annualSalary);
    
    printf("Input the number of years worked: ");
    scanf("%d", &numYears);
    
    if (numYears >= 10) {
        retirementCalc = 0.03 * annualSalary * numYears;
    } else if (numYears < 10) {
        retirementCalc = (0.25 * 0.021 * numYears) * annualSalary;
    }
    
    printf("The employee's projected retirement salary is: $%.2lf\n", retirementCalc);
}
