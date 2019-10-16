// CS 271
// Program Name: Term.cpp
// Author:       Zachary Neeley
// Date:         11/6/2018
// Purpose:      This program will use the Term.cpp class to test out operator overloading.

#include <iostream>
#include <iomanip>
#include "Term.h"

using namespace std;

// Constructor will take a coefficient and exponent from the user or will set them to 0 by default
Term::Term(int coef, int exp) {
    coefficient = coef;
    exponent = exp;
    
} // end Constructor

// Mutator will change the coefficient
void Term::setCoefficient(int c) {
    coefficient = c;
    
} // end setCoefficient

// Mutator will change the exponent
void Term::setExponent(int e) {
    exponent = e;
    
} // end setExponent

// Accessor for the coefficient
int Term::getCoefficient() {
    return coefficient;
    
} // end getCoefficient

// Accessor for the coefficient
int Term::getExponent() {
    return exponent;
    
} // end exponent

// operator overloading for << will take the coefficient and exponent, creating a print like: 3x^6
ostream& operator<<( ostream &out, const Term &t) {
    out << t.coefficient << "x^" << t.exponent;
    return out;
    
} // end <<

// operator overloading for >> will take in 2 integers and store them into the coefficient and exponent
istream& operator>>( istream &in, Term &t) {
    
    // init
    int c, e;
    
    // Take in the coefficient
    in >> c;
    
    // Ignore the x^ from the input
    in.ignore();
    in.ignore();
    
    // Take in the exponent
    in >> e;
    
    // Set the 2 values in the term
    t.setCoefficient(c);
    t.setExponent(e);
    return in;
    
} // end >>

// operator overloading + will add 2 numbers with exponents to each other
Term Term::operator+ (const Term &t) const {
    
    // Create a new Term Object
    Term temp;
    
    // See if the exponents are different if so set both the exponent and coefficient to 0
    if (t.exponent != exponent) {
        temp.setCoefficient(0);
        temp.setExponent(0);
        return temp;
        
    } // end if
    
    // Add the coefficients and set the exponent of temp
    temp.setCoefficient(t.coefficient + coefficient);
    temp.setExponent(exponent);
    return temp;
    
} // end +

// operator overloading - will subtract 2 numbers with exponents to each other
Term Term::operator- (const Term &t) const {
    
    // Create a new Term Object
    Term temp;
    
    // See if the exponents are different if so set both the exponent and coefficient to 0
    if (t.exponent != exponent) {
        temp.setCoefficient(0);
        temp.setExponent(0);
        return temp;
    } // end if
    
    // Subtract the coefficients and set the exponent of temp
    temp.setCoefficient(t.coefficient - coefficient);
    temp.setExponent(exponent);
    return temp;
    
} // end -

// operator overloading * will multiply 2 numbers with exponents to each other
Term Term::operator* (const Term &t) const {
    
    // Create a new Term Object
    Term temp;
    
    // multiply the 2 coefficients and add the exponents in temp
    temp.setCoefficient(t.coefficient * coefficient);
    temp.setExponent(t.exponent + exponent);
    
    return temp;
    
} // end *
