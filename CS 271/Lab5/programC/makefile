all: programC

programC: programC.o funcations.o
	gcc programC.o funcations.o -o programC

programC.o: 
	gcc -c programC.c

funcations.o:
	gcc -c funcations.c

clear:
	rm *.o 
