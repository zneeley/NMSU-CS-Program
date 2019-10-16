/*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015
*/

/*
	Name: Zachary Neeley
	Date: 2/17/19
	Description: This lex file will take input from the console convert the input into tokens than pass onto the YACC file.
	Changes: Added the "int" for the INT token.
			 Added the ; to the symbols to be returned. 
			 Changed the return for [a-z]+ so the YACC union string will have a copy using strdup of the token. 
			 Changed the return for [0-9][0-9]* so the YACC union value will have a copy of the int using atoi.

*/
%{

int mydebug = 0;
int lineNum = 0;
#include "y.tab.h"
%}


%%
"int"      {return (INT);}

[a-z]+		{if (mydebug) fprintf(stderr,"Letter found\n"); 
                       yylval.string=strdup(yytext); return VARIABLE;}
                       
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                       yylval.value=atoi((const char *)yytext); return(INTEGER);}
                       
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}

[=\-+*/%&|();] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext);
                       return (*yytext);}
                       
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext);
                       lineNum = lineNum + 1; 
                       return (*yytext);}

%%

int yywrap(void)
{ return 1;}


