# Name: Zachary Neeley
# Date: 4/10/19
# Description: Makefile for Lab 7 CS 370
all: lab9LEX.l lab9YACC.y symtable.c y.tab.c lex.yy.c EMITast.c 
	yacc -d lab9YACC.y
	lex lab9LEX.l
	gcc y.tab.c ast.c ast.h symtable.c symtable.h EMITast.c EMITast.h lex.yy.c -o lab9
	./lab9 -o test -d < input.asm
	
