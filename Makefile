CXX=g++
CXXFLAGS=-Wall -std=gnu++0x
LDFLAGS=

all: pmake.o

pmake.o: pmake.cpp
	$(CXX) $(CXXFLAGS) -o pmake pmake.cpp
