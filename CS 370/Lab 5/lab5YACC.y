%{

/*
 * Name: Zachary Neeley
 * Date: 1/25/19
 * Purpose: The prupose of this program is to create a calculator using LEX and YACC
 *          to learn the basic process of tokens, expressions and basic trees.
 *     
 *      Input: Numbers and characters ex: -2*(5+3)
 *      Output: Show each token read in the input and the the digit found. Finially
 *              showing an answer.
 *      Assumption: 
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

extern int lineNum;

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

%token <value> NUM
%token <string> ID
%token AND OR NOT INT VOID WHILE DO IF THEN ELSE READ WRITE FOR RETURN LE GE EQ NE
%token MYBEGIN END OF BOOLEAN TRUE FALSE


%%	/* end specs, begin rules */

program     : decl-list
            ;

decl-list   : decl
            | decl decl-list
            ;

decl        : var-decl
            | fun-decl
            ;

var-decl    : type-spec var-list
            ;

var-list    : ID
            | ID '[' NUM ']'
            | ID ',' var-list
            | ID '[' NUM ']' ',' var-list
            ;

type-spec   : int
            | void
            | boolean
            ;

fun-decl    : type-spec ID '(' params ')' comp-stmt
            ;

params      : void
            | param-list
            ;

param-list  : param
            | param ',' param
            ;

param       : type-spec ID '['']'
            | type-spec ID
            ;

comp-stmt   : MYBEGIN local-decl stmt-list END
            ;

local-decl  : var-decl
            ;

stmt-list   : stmt
            ;

stmt        : expr-stmt
            | comp-stmt
            | selc-stmt
            | iter-stmt
            | ass-stmt
            | return-stmt
            | read-stmt
            | write-stmt
            ;

expr-stmt   : expression ';'
            | ';'
            ;

selc-stmt   : IF expression THEN statement 
            | IF expression THEN statement ELSE statement +
            ;

iter-stmt   : WHILE expression DO statement
            ;

return-stmt : RETURN ';'
            | RETURN expression ';'
            ;

read-stmt   : READ varariable ';'
            ;

write-stmt  : WRITE expression ';'
            ;

ass-stmt    : variable '=' sim-expr ';'
            ;

expression  : sim-expr
            ;

variable    : ID '[' expression ']'
            | ID '[' ']'
            ;

sim-expr    : add-expr
            | add-expr relop add-expr
            ;

relop       : LE | '<' | '>' | GE | EQ | NE
            ;

add-expr    : term 
            | addop term
            ;

addop       : '+' | '-'
            ;

term        : factor
            | multop factor
            ;

multop      : '*' | '/' | AND | OR
            ;

factor      : '(' expression ')' 
            | NUM | variable | call | TRUE | FALSE | NOT factor
            ;

call        : ID '(' args ')'
            ;

args        : arg-list | /* EMPTY */
            ;

arg-list    : expression 
            | expression ',' expression arg-list 
            | /* EMPTY */
            ;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
