
all: Lab10

Lab10: Lab10.o TwoDayPackage.o Package.o
	g++ Lab10.o TwoDayPackage.o Package.o -o Lab10

Lab10.o: Lab10.cpp TwoDayPackage.h Package.h
	g++ Lab10.cpp TwoDayPackage.h Package.h -c

TwoDayPackage.o: TwoDayPackage.cpp TwoDayPackage.h
	g++ TwoDayPackage.cpp TwoDayPackage.h -c

Package.o: Package.cpp Package.h
	g++ Package.cpp Package.h -c

clean:
	rm *.o
