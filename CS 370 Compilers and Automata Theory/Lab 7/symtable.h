/*  Symbol Table --linked list  headers
    Used for Compilers class

    Modified Spring 2015 to allow for name to pointed to by symtable, instead of copied, since the name is copied
    into the heap

    Modified to have levels.  A level 0 means global variable, other levels means in range of the function.  We
    start out our offsets at 0 (from stack pointer) for level 1,,,when we enter a functional declaration.
    We increment offset each time we insert a new variable.  A variable is considered to be valid if it is found in
    the symbol table at our level or lesser level.  If at 0, then it is global.  

    We return a pointer to the symbol table when a variable matches our creteria.

    We add a routine to remove variables at our level and above.
*/

/*
 * Name: Zachary Neeley
 * Date: 4/10/19
 * Purpose: The purpose of this program is to create a code interperator using LEX and YACC
 *          to generate a abstract syntax tree.
 *     
 *      Input: Any valid line of a algol C language. Ex int x[100], y;
 *      Output: A generated abstract syntax tree of the given input and a symbol table from the tree.
 * 
 */    

#include "ast.h"

#ifndef _SYMTAB 
#define _SYMTAB

void Display();
int Delete(int level);

int FetchAddr (char *lab);

struct SymbTab
{
     char *name;
     int offset; /* from activation record boundary */
     int mysize;  /* number of words this item is 1 or more */
     int level;  /* the level where we found the variable */
     enum OPERATORS Type;  /* the type of the symbol */
     int IsAFunc;  /* the element is a function */
     ASTnode * fparms; /* pointer to parameters of the function in the AST */

     struct SymbTab *next;
};


struct SymbTab * Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset, ASTnode * fparms );


// Add the needed prototypes for the functions in symtable.c
void PrintSym(struct SymbTab *s);

void Display();

struct SymbTab * Search(char name[], int level, int recur);

int Delete(int level);

char * CreateTemp();

int compareFormula(ASTnode *fparms, ASTnode *args);
#endif
