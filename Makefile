CXX=g++-4.7
CXXFLAGS=-g -Wall -std=gnu++0x
LDFLAGS=

all: pmake.o

pmake.o: pmake.cpp
	$(CXX) $(CXXFLAGS) -o pmake pmake.cpp
