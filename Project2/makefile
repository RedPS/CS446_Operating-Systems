sim2: sim2.o Configuration.o Functions.o MetaData.o CustomException.o MemoryAllocation.o ProcessControl.o Clock.o
	g++ -std=c++0x -Wall sim2.o Configuration.o Functions.o MetaData.o CustomException.o MemoryAllocation.o ProcessControl.o Clock.o -pthread -o sim2

sim2.o: sim2.cpp
	g++ -c sim2.cpp

Configuration.o: Configuration.cpp Configuration.h
	g++ -c Configuration.cpp

Functions.o: Functions.cpp
	g++ -c Functions.cpp

MetaData.o: MetaData.h MetaData.cpp
	g++ -c MetaData.cpp

CustomException.o: CustomException.h CustomException.cpp
	g++ -c CustomException.cpp

MemoryAllocation.o: MemoryAllocation.h MemoryAllocation.cpp
	g++ -c MemoryAllocation.cpp

ProcessControl.o: ProcessControl.h ProcessControl.cpp
	g++ -c ProcessControl.cpp

Clock.o: Clock.h Clock.cpp
	g++ -c Clock.cpp


clean:
	rm *.o sim2
