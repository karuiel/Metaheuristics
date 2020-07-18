CC = g++ -std=c++11 -Ofast -funroll-all-loops
CPPFLAGS = -Wall -std=c++11 -g -I$(INC) -c
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)


all: $(BIN)/APC
	
$(BIN)/APC: $(OBJECTS)
	$(CC) -g -o $@ -I$(INCLUDE) -I$(SRC) $^

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -g -I$(INCLUDE) -I$(SRC) -o $@ -c $<

doc:
	doxygen $(DOC)/doxys/Doxyfile

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc
