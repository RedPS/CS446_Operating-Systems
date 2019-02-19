sim01: sim01.o Configuration.o Functions.o MetaData.o CustomException.o
	g++ -std=c++0x -Wall sim01.o Configuration.o Functions.o MetaData.o CustomException.o -o sim01

sim01.o: sim01.cpp
	g++ -c sim01.cpp

Configuration.o: Configuration.cpp Configuration.h
	g++ -c Configuration.cpp

Functions.o: Functions.cpp
	g++ -c Functions.cpp

MetaData.o: MetaData.h MetaData.cpp
	g++ -c MetaData.cpp

CustomException.o: CustomException.h CustomException.cpp
	g++ -c CustomException.cpp

clean:
	rm *.o sim01
