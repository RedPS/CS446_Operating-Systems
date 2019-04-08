sim3: sim3.o Configuration.o SystemOperation.o MetaData.o CustomException.o  ProcessControl.o Output.o
	g++ -std=c++0x -Wall sim3.o Configuration.o SystemOperation.o MetaData.o CustomException.o ProcessControl.o Output.o -pthread -o sim3


sim3.o: sim3.cpp
	g++ -c sim3.cpp

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

clean:
	rm *.o sim3
