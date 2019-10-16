all: Lab8

Lab8: Lab8.o Date.o LongDate.o
	g++ Lab8.o Date.o LongDate.o -o Lab8

Lab.o: Lab8.cpp Date.h LongDate.h
	g++ -c Lab8.cpp

LongDate.o: LongDate.cpp LongDate.h
	g++ -c LongDate.cpp

Date.o: Date.cpp Date.h
	g++ -c Date.cpp

clean:
	rm *.o
