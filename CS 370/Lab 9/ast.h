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

#include<stdio.h>
#include<malloc.h>


#ifndef AST_H
#define AST_H

/* define the enumerated types for the AST.  THis is used to tell us what 
sort of production rule we came across */

// This is every type of an abstract syntax tree needed for proper use.
enum ASTtype {
   PROGRAM,
   varDecl,
   funDecl,
   IDENT,
   NUMBER,
   expression,
   ifElse,
   ifStmt,
   param,
   compStmt,
   localDecl,
   variable,
   call,
   writeStmt,
   readStmt,
   assignStmt,
   returnStmt,
   iterStmt,
   selcStmt
}; // end ASTtype


// All the operators that are accepted into the program which are needed for showing the 
// symboles needed during the print out of the program.
enum OPERATORS {
   PLUS,
   MINUS,
   TIMES,
   DIVIDE,
   MYNOT,
   MYOR,
   MYAND,
   LESSTHAN,
   GREATERTHAN,
   EQUALTO,
   LESSTHANEQ,
   GREATERTHANEQ,
   NOTEQUAL
};// end operator


// Add a enum for the needed types
enum SYSTYPE {
    BOOLTYPE,
   VOIDTYPE,
   STRINGTYPE,
   INTTYPE
};
/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code 
*/

// All the needed pointers and data variables for the ASTnode
typedef struct ASTnodetype
{
     enum ASTtype type;
     enum OPERATORS operator;
     enum SYSTYPE isType;
     char * name;
     char * label;
     int value;
     int size;
     struct SymbTab *symbol;
     struct ASTnodetype *s1,*s2, *next ; /* used for holding IF and WHILE components -- not very descriptive */
} ASTnode; // end ASTnode

#include "symtable.h"
/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum ASTtype mytype);

// A function used to add spaces into the output
void PT(int howmany);

// NOT USED but this would connect 2 nodes using the next pointer
void ASTattachnext(ASTnode *p,ASTnode *q);

// A pointer of a ASTnode named *program
ASTnode *program;

/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p);

#endif // of AST_H
