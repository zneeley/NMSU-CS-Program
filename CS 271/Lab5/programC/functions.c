#include "functions.h"

double integerPower(int base, int exp) {
    double ans = 1, equation, temp = 1;
    
    equation = temp/base;
    
    if (exp == 0) {
        ans = 1.0;
    }
    
    if(exp > 0) {
        for (int i = 1; i <= exp; i++) {
        ans = ans * base;
        
        }
    } else if (exp < 0){
        for (int i = -1; i >= exp; i--) {
            
            ans = ans * equation;
        }
    }
    
    return ans;
}
