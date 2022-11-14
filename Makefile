#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------


#Etapas para adicionar modulos:
#	1. Adicionar formula do objeto para saber o que eh necessario para sua compilacao
#	2. Adicionar objeto a variavel OBJS
#	3. Adicionar headers necessarios para compilacao em HDRS

CPP = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
#ADICIONAR NOS OBJETOS O QUE DEVE SER RASTREADO DE MUDANCA:
OBJS = $(OBJ)/recQuicksort.o $(OBJ)/heapsort.o $(OBJ)/dumbPileQuicksort.o $(OBJ)/medQuicksort.o $(OBJ)/pileQuicksort.o $(OBJ)/selQuicksort.o $(OBJ)/dados.o $(OBJ)/main.o
#ADICIONAR NOS HEADERS OS INCLUDES NECESSARIOS PARA COMPILACAO:
HDRS = $(INC)/recQuicksort.hpp $(INC)/selQuicksort.hpp $(INC)/dumbPileQuicksort.hpp $(INC)/pileQuicksort.hpp $(INC)/heapsort.hpp $(INC)/medQuicksort.hpp $(INC)/dados.hpp $(INC)/msgassert.h
CPFLAGS = -Wall -c -I$(INC)
CXXFLAGS = -std=c++11 -g -Wall

EXE = $(BIN)/quicksort

all:  $(EXE)

test: $(TEST)



$(BIN)/quicksort: $(OBJS)
	$(CPP) $(CXXFLAGS) -pg -I$(INC) -o $(BIN)/quicksort $(OBJS) $(LIBS) 

# Formulas para os objetos:

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp -g

$(OBJ)/recQuicksort.o: $(HDRS) $(SRC)/recQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/recQuicksort.o $(SRC)/recQuicksort.cpp

$(OBJ)/heapsort.o: $(HDRS) $(SRC)/heapsort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/heapsort.o $(SRC)/heapsort.cpp

$(OBJ)/dumbPileQuicksort.o: $(HDRS) $(SRC)/dumbPileQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/dumbPileQuicksort.o $(SRC)/dumbPileQuicksort.cpp
	
$(OBJ)/medQuicksort.o: $(HDRS) $(SRC)/medQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/medQuicksort.o $(SRC)/medQuicksort.cpp

$(OBJ)/selQuicksort.o: $(HDRS) $(SRC)/selQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/selQuicksort.o $(SRC)/selQuicksort.cpp

$(OBJ)/pileQuicksort.o: $(HDRS) $(SRC)/pileQuicksort.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/pileQuicksort.o $(SRC)/pileQuicksort.cpp -g
	
$(OBJ)/dados.o: $(HDRS) $(SRC)/dados.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/dados.o $(SRC)/dados.cpp -g

	
	
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
