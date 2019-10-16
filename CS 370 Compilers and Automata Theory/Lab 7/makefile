# Name: Zachary Neeley
# Date: 4/10/19
# Description: Makefile for Lab 7 CS 370
all: lab7LEX.l lab7YACC.y symtable.c y.tab.c lex.yy.c
	yacc -d lab7YACC.y
	lex lab7LEX.l
	gcc y.tab.c ast.c ast.h symtable.c symtable.h lex.yy.c -o lab7
	./lab7 < lab7example.al

	
