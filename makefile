CXX=g++
CXXFLAGS=-std=c++11 
BIN=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: 	$(OBJ)
	$(CXX) -o $(BIN) $^

%.o: 	%.c
	$(CXX) $@ -c $<

clean:
	rm *.o
	rm $(BIN)
