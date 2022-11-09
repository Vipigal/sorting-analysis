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
OBJS = $(OBJ)/recQuicksort.o $(OBJ)/main.o 
HDRS = $(INC)/recQuicksort.hpp
CPFLAGS = -Wall -c -I$(INC)
CXXFLAGS = -std=c++11 -g -Wall

EXE = $(BIN)/analysis


all:  $(EXE)

test: $(TEST)



$(BIN)/analysis: $(OBJS)
	$(CPP) $(CXXFLAGS) -pg -I$(INC) -o $(BIN)/analysis $(OBJS) $(LIBS) 

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/recQuicksort.o: $(HDRS) $(SRC)/recQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/recQuicksort.o $(SRC)/recQuicksort.cpp
	
# $(OBJ)/inbox.o: $(HDRS) $(SRC)/inbox.cpp
# 	$(CPP) $(CPFLAGS) -o $(OBJ)/inbox.o $(SRC)/inbox.cpp
	
# $(OBJ)/user.o: $(HDRS) $(SRC)/user.cpp
# 	$(CPP) $(CPFLAGS) -o $(OBJ)/user.o $(SRC)/user.cpp

	
	
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
