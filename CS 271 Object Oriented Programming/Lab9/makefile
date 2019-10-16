all: Lab9

Lab9: Lab9.o Term.o
	g++ Term.o Lab9.o -o Lab9

Lab9.o: Lab9.cpp Term.h
	g++ Lab9.cpp Term.h -c

Term.o: Term.cpp Term.h
	g++ Term.cpp Term.h -c

clean:
	rm *.o
