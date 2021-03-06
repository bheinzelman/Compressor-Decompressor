CXXFLAGS=-std=c++11 
BIN=bzip

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: 	$(OBJ)
	$(CXX) -o  $(BIN) $^

%.o: 	%.c
	$(CXX) $(CXXFLAGS) $@ -c $<

clean:
	rm *.o
	rm $(BIN)
