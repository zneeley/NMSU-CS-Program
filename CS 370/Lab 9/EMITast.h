/*
 * Name: Zachary Neeley
 * Date: 5/3/19
 * Purpose: The purpose of this program is to create a code interperator using LEX and YACC
 *          to generate a abstract syntax tree.
 *     
 *      Input: Any valid line of a algol C language. Ex int x[100], y;
 *      Output: A generated abstract syntax tree of the given input and a symbol table from the tree with a NASM generated files.
 * 
 */

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include "ast.h"

#ifndef EMITast_H
#define EMITast_H

FILE *fp;

// Postcondition: A generate label following _L(NUM) for any needed information.
char * CreateLabel();

// Precondition: ASTnode from a completed yacc parse.
// Postcondition: A NASM file that runs the code given.
void emitAst(ASTnode *p);

// Precondition: ASTnode of varDecl.
// Postcondition: The printed information for globals.
void emitGlobals(ASTnode *p);

// Precondition: A ASTnode with a type of funDecl.
// Postcondition: Will print out the needed information to a file with the needed stack pointer and offset for the activation record.
void emitLabelStart(ASTnode *p);

// Precondition: ASTnode of writeStmt
// Postcondition: Added strings to the output file under the .data section
void emitIdent(ASTnode *p);

// Precondition: ASTnode with a type of variable.
// Postcondition: RAX will contain the value of the identifier.
void emitStrings(ASTnode *p);

// Precondition: ASTnode of expression
// Postcondition: RAX will contain the final of the expression
void emitExpr(ASTnode *p);

// Precondition: ASTnode of assignStmt
// Postcondition: RAX will contain the final value
void emitAssign(ASTnode *p);

// Precondition: The funtion has been printed to the file.
// Postcondition: Finish the activation record adding a return when needed.
void emitLabelEnd();

// Precondition: ASTnode of ifStmt
// Postcondition: Output file will contain the needed labels and logic to handle an ifStmt.
void emitIF(ASTnode *p);

// Precondition: ASTnode of iterStmt
// Postcondition: Output file will contain the needed labels and information needed for a while loop
void emitWhile(ASTnode *p);

#endif
