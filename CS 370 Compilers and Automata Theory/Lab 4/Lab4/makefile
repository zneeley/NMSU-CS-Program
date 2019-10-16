#Zachary Neeley
#Date: 02/17/2019
#Description: makefile that will compile the new calculator.
all:
	yacc -d lab4docalc.y
	lex lab4docalc.l
	gcc symtable.c -c 
	gcc y.tab.c -o lab4
