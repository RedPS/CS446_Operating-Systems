sim4: sim4.o Configuration.o SystemOperation.o MetaData.o CustomException.o Scheduling.o ProcessControl.o Output.o
	g++ -std=c++0x -Wall sim4.o Scheduling.o Configuration.o SystemOperation.o MetaData.o CustomException.o ProcessControl.o Output.o -pthread -o sim4


sim4.o: sim4.cpp
	g++ -c sim4.cpp

Configuration.o: Configuration.cpp Configuration.h
	g++ -c Configuration.cpp

SystemOperation.o: SystemOperation.cpp
	g++ -c SystemOperation.cpp

MetaData.o: MetaData.h MetaData.cpp
	g++ -c MetaData.cpp

CustomException.o: CustomException.h CustomException.cpp
	g++ -c CustomException.cpp

ProcessControl.o: ProcessControl.h ProcessControl.cpp
	g++ -c ProcessControl.cpp

Output.o: Output.h Output.cpp
	g++ -c Output.cpp

Scheduling.o: Scheduling.h Scheduling.cpp
	g++ -c Scheduling.cpp

clean:
	rm *.o sim4
