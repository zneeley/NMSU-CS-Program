//
//  HEADER
//
// 1) This program takes the string input of "ab x" which is used in the mystery2 to remove //  //    the space.
//
// 2) The contents of s[6] = ""; Empty or nothing because if that room is not being used then //    the elements are empty.
//
// 3) 
// 
// 4) The output of the program is:
//      ad x
//      adx

#include <stdio.h>

void mystery2(const char *s) {
    
    char *t;
    
    for (t=s ; *t = *s; s++) {
        if (*t != ' ') {
            t++;
        }
    }
}


int main(void) {
    
    char s[6] = "ab x";
    printf("%s\n", s);
    mystery2(s);
    printf("%s\n", s);
}
