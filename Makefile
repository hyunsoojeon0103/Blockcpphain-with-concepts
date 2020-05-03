CC = g++
CXX = g++

INCLUDES = 

CXXFLAGS = -g -Wall $(INCLUDES) -std=c++2a 

LDFLAGS= -g

executables = main
objects = main.o sha256.o

.PHONY: default
default: $(executables)

$(executables): sha256.o

$(objects): Block.h Blockchain.h sha256.h json.hpp uint256.h

.PHONY: clean
clean:
	rm -f *~ $(objects) $(executables) .*.un~

.PHONY: all
all: clean default
