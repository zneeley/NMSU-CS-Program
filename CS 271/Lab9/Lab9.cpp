// CS 271
// Program Name: Lab9
// Author:       Zachary Neeley
// Date:         11/6/2018
// Purpose:      This program will use the Term.cpp class to test out operator overloading.

#include <iostream>
#include <iomanip>
#include "Term.h"

using namespace std;

int main() {
    
    // init create 2 numbers with exponents 
    Term k(2,3);
    Term r;
    
    // Read in a new number into r
    cout << "Please input a number with an exponent ex) 2^5 " << endl;
    cin >> r;
    
    cout << "The sum of k and r is "<< (k + r) << endl;
    
    cout << "The difference of k and r is " << (k - r) << endl;
    
    cout << "The product of k and r is "<< (k * r) << endl;
    
} // end main
