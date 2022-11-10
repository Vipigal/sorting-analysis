#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CPP = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/recQuicksort.o $(OBJ)/medQuicksort.o $(OBJ)/selQuicksort.o $(OBJ)/dados.o $(OBJ)/main.o 
HDRS = $(INC)/recQuicksort.hpp $(INC)/selQuicksort.hpp $(INC)/medQuicksort.hpp $(INC)/dados.hpp $(INC)/msgassert.h
CPFLAGS = -Wall -c -I$(INC)
CXXFLAGS = -std=c++11 -g -Wall

EXE = $(BIN)/quicksort
DEBUG = $(BIN)/quicksort


all:  $(EXE)

test: $(TEST)


$(BIN)/quicksort: $(OBJS)
	$(CPP) $(CXXFLAGS) -pg -I$(INC) -o $(BIN)/quicksort $(OBJS) $(LIBS) 

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp -g

$(OBJ)/recQuicksort.o: $(HDRS) $(SRC)/recQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/recQuicksort.o $(SRC)/recQuicksort.cpp
	
$(OBJ)/medQuicksort.o: $(HDRS) $(SRC)/medQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/medQuicksort.o $(SRC)/medQuicksort.cpp -g

$(OBJ)/selQuicksort.o: $(HDRS) $(SRC)/selQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/selQuicksort.o $(SRC)/selQuicksort.cpp -g
	
$(OBJ)/dados.o: $(HDRS) $(SRC)/dados.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/dados.o $(SRC)/dados.cpp -g

	
	
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
