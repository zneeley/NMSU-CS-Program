/*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015
*/
%{

int mydebug = 1;
int lineNum = 0;
#include "y.tab.h"
%}


%%
"int"      {return (INT);}
"and"      {return (AND);}
"or"       {return (OR);}
"not"      {return (NOT);}
"void"     {return (VOID);}
"while"    {return (WHILE);}
"do"       {return (DO);}
"if"       {return (IF);}
"then"     {return (THEN);}
"else"     {return (ELSE);}
"read"     {return (READ);}
"write"    {return (WRITE);}
"for"      {return (FOR);}
"return"   {return (RETURN);}
"boolean"  {return (BOOlEAN);}
"<="       {return (LE);}
">="       {return (GE);}
"=="       {return (EQ);}
"!="       {return (NE);}
"of"       {return (OF);}
"true"     {return (TRUE);}
"false"    {return (FALSE);}
"begin"    {return (MYBEGIN);}
"end"      {return (END);}

[a-z][a-zA-Z0-9]*		{if (mydebug) fprintf(stderr,"ID found\n"); 
                       yylval.string=strdup(yytext); return (ID);}
                       
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"NUM found\n"); 
                       yylval.value=atoi((const char *)yytext); return(NUM);}
                       
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}

[=\-+*/%&|();<>] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext);
                       return (*yytext);}
                       
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext);
                       lineNum = lineNum + 1;}

%%

int yywrap(void)
{ return 1;}


