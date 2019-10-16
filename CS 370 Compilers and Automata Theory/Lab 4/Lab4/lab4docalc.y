%{

/*
 * Name: Zachary Neeley
 * Date: 2/17/19
 * Purpose: The prupose of this program is to create a calculator using LEX and YACC
 *          to learn the basic process of tokens, expressions and basic trees.
 *     
 *      Input: Tokens given by the LEX file.
 *      Output: Show each token read in the input and the the digit found. Finially
 *              showing an answer.
 *
 * Changes: Added a union to store the int value and char * string of the incoming variables.
 * 			Changed the tokens so thar the incoming integer is stored in value and the incoming variable is stored in string and a token for int.
 *			Added a MAXSTACK for size checking.
 *			Changed the program start to point to decls and list.
 *			Added decls which can be a decl follow by a decls.
 *			Added decl for checking the symbol table for the new values and to add anything new to the program.
 *			Changed the stat so that when the variable is initlized the program will get the proper address (offset)
 *			Changed the variable so that it will get the proper address.
 * 			
 */


/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correct memmory look up or the storage depending
   on position

   Shaun Cooper
    January 2015

   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "lex.yy.c"
#include "symtable.c"
#define MAXSTACK 26

extern int lineNum;
int regs[MAXSTACK];
int offset = 0;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union {
    int value;
    char * string;
}

%token <value> INTEGER
%token <string> VARIABLE
%token INT
%type <value> expr


%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


%%	/* end specs, begin rules */

program     :   decls list
            ;

decls   :    /* empty */
        | decl decls
        ;
        
decl    :    INT VARIABLE ';' '\n' {
                if (Search($2)) {
                    /* If the dec is already in the list */
                    fprintf(stderr, "Error Line %d: Symbol %s already defined.\n",lineNum, $2);
                    exit(0);
                } else {
                    if (offset < MAXSTACK) {
						/* Add the new variable to the table with its offset */
                        Insert($2, offset);
                        offset++;
                    } else {
                        printf("Max number of variables used.\n");
                    }
                }
            };
           
list    :     /* empty */
        | list error '\n'
        | list stat  '\n'
            { yyerrok; }
        ;
        
stat	:	expr
			{ fprintf(stderr,"The answer is %d.\n", $1); }
	|	VARIABLE '=' expr 
			{ if (Search($1)) {
				/* If the variable is initlized get the proper address */
                regs[fetchAddress($1)] = $3;
              } else {
                printf("Error: Variable not declared.\n");
                exit(0);
              }
            }
	;
	
	
expr	:	'(' expr ')'
			{ $$ = $2; }
	|	expr '-' expr
			{ $$ = $1 - $3; }
	|	expr '+' expr
			{ $$ = $1 + $3;}
	|	expr '/' expr
			{ $$ = $1 / $3; }
	|	expr '%' expr
			{ $$ = $1 % $3; }
	|	expr '&' expr
			{ $$ = $1 & $3; }
	|	expr '|' expr
			{ $$ = $1 | $3; }
    |	expr '*' expr
			{ $$ = $1 * $3; }
	|	'-' expr	%prec UMINUS
			{ $$ = -$2; }
	|	VARIABLE
			{ if (Search($1)) {
				/* Store the proper address in $$ */
                $$ = regs[fetchAddress($1)]; 
                fprintf(stderr,"Found a variable value = %s.\n", $1); 
              } else {
                printf("Error: Variable not declared.\n");
                exit(0);
              }
            }
              
	|	INTEGER {$$ = $1; fprintf(stderr,"Found an integer.\n");}
	;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
