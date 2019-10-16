all: lab3

lab3: lab3.o helperfunctions.o sortingfunctions.o
	gcc lab3.o helperfunctions.o sortingfunctions.o -o lab3

lab3.o: lab3.c helperfunctions.h sortingfunctions.h
	gcc -c lab3.c

helperfunctions.o: helperfunctions.c helperfunctions.h
	gcc -c helperfunctions.c

sortingfunctions.o: sortingfunctions.c sortingfunctions.h
	gcc -c sortingfunctions.c

clean:
	rm -rf *.o
