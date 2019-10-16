/*
 * Name: Zachary Neeley
 * Date: 2/27/19
 * Purpose: The purpose of this program is to create a code interperator using LEX and YACC
 *          to learn the general process of tokens, expressions and basic trees.
 *     
 *      Input: Numbers and characters ex: int x[100],y, z;
 *      Output: Any syntax errors in the code and their line number
 * 
 */
 
%{

int lineNum = 1;
int mydebug = 0;
#include "y.tab.h"
%}


%%
"int"      {if (mydebug) fprintf(stderr,"INT found\n"); return(INT);}
"and"      {if (mydebug) fprintf(stderr,"AND found\n"); return (AND);}
"or"       {if (mydebug) fprintf(stderr,"OR found\n"); return (OR);}
"not"      {if (mydebug) fprintf(stderr,"NOT found\n"); return (NOT);}
"void"     {if (mydebug) fprintf(stderr,"VOID found\n"); return (VOID);}
"while"    {if (mydebug) fprintf(stderr,"WHILE found\n"); return (WHILE);}
"do"       {if (mydebug) fprintf(stderr,"DO found\n"); return (DO);}
"if"       {if (mydebug) fprintf(stderr,"IF found\n"); return (IF);}
"then"     {if (mydebug) fprintf(stderr,"THEN found\n"); return (THEN);}
"else"     {if (mydebug) fprintf(stderr,"ELSE found\n"); return (ELSE);}
"read"     {if (mydebug) fprintf(stderr,"READ found\n"); return (READ);}
"write"    {if (mydebug) fprintf(stderr,"WRITE found\n"); return (WRITE);}
"for"      {if (mydebug) fprintf(stderr,"FOR found\n"); return (FOR);}
"return"   {if (mydebug) fprintf(stderr,"RETURN found\n"); return (RETURN);}
"boolean"  {if (mydebug) fprintf(stderr,"BOOLEAN found\n"); return (BOOLEAN);}
"<="       {if (mydebug) fprintf(stderr,"<= found\n"); return (LE);}
">="       {if (mydebug) fprintf(stderr,">= found\n"); return (GE);}
"=="       {if (mydebug) fprintf(stderr,"== found\n"); return (EQ);}
"!="       {if (mydebug) fprintf(stderr,"!= found\n"); return (NE);}
"of"       {if (mydebug) fprintf(stderr,"OF found\n"); return (OF);}
"true"     {if (mydebug) fprintf(stderr,"TRUE found\n"); return (TRUE);}
"false"    {if (mydebug) fprintf(stderr,"FALSE found\n"); return (FALSE);}
"begin"    {if (mydebug) fprintf(stderr,"BEGIN found\n"); return (MYBEGIN);}
"end"      {if (mydebug) fprintf(stderr,"END found\n"); return (MYEND);}

[a-zA-Z][a-zA-Z0-9]*		{if (mydebug) fprintf(stderr,"ID found\n"); 
                       yylval.string=strdup(yytext); return (ID);}
                       
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"NUM found\n"); 
                       yylval.value=atoi((const char *)yytext); return(NUM);}
                       
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}

[=\-+*/%&|();<>,\[\]] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext);
                       return (*yytext);}
                       
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext);
                       lineNum = lineNum + 1;}

%%

int yywrap(void)
{ return 1;}


