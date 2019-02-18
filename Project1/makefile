CPPFLAGS = -std=c++11 -w

all: sim01

sim01: sim01.o
	g++ $(CPPFLAGS) -o  sim01 sim01.o

sim01.o: Configuration.cpp Configuration.h Functions.cpp MetaData.h MetaData.cpp

clean:
	rm -f sim01; rm -f sim01.o
