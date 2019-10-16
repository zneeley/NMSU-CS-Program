//
//  HEADER
//
// 1) This program takes the string "asdx ddf gf" and counts how many characters are in the //  //    string.
//
// 2) The formal parameter in mystery1 is the char *s.
//
// 3) The actual parameter in mystery1 is the int i.
//
// 4) The *s role in the loop is the string input to the method which is "asdx ddf gf".

#include <stdio.h>

int mystery1(const char *s) {
    int i; 

    for (i=0 ; *s; i++, s++); /* empty body */
        return i;
    }

int main(void) {

    printf("%d\n", mystery1("asdx ddf gf"));
}
