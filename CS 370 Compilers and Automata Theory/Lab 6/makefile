# Name: Zachary Neeley
# Date 2/27/19
# Description: Makefile for Lab 6 CS 370
all:
	yacc -d lab6YACC.y
	lex lab6LEX.l
	gcc lex.yy.c y.tab.c -o lab6
	./lab6 < lab6test.al

	
