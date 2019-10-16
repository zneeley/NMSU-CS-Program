// CS 271
// Program Name: Term.h
// Author:       Zachary Neeley
// Date:         11/6/2018
// Purpose:      Will be used with the Term.cpp implimentation. 

#ifndef TERM_H
#define TERM_H
#include <iostream>

using namespace std;

class Term {
    friend ostream& operator<<( ostream &out, const Term &t );
    friend istream& operator>>( istream &in, Term &t );

    private:
        int coefficient;
        int exponent;

    public:
        Term ( int coef = 0, int exp = 0 );
        void setCoefficient ( int );
        void setExponent ( int );
        int getCoefficient ();
        int getExponent( );
        Term operator+ (const Term & ) const;
        Term operator- (const Term & ) const;
        Term operator* (const Term & ) const;
}; 
#endif
