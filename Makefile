# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -I./CoreModul -I./Cards -I./GameUI

# Linker flags
LDFLAGS = 

# Source files
SRC_MAIN = ConsoleBang!.cpp
SRC_COREMODUL = $(wildcard CoreModul/*.cpp)
SRC_CARDS = $(wildcard Cards/*.cpp)
SRC_GAMEUI = $(wildcard GameUI/*.cpp)

# Object files
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_COREMODUL = $(SRC_COREMODUL:.cpp=.o)
OBJ_CARDS = $(SRC_CARDS:.cpp=.o)
OBJ_GAMEUI = $(SRC_GAMEUI:.cpp=.o)

# Executable name
EXEC = ConsoleBang

# Default target
all: $(EXEC)

# Rule to link the executable
$(EXEC): $(OBJ_MAIN) $(OBJ_COREMODUL) $(OBJ_CARDS) $(OBJ_GAMEUI)
	$(CXX) $(OBJ_MAIN) $(OBJ_COREMODUL) $(OBJ_CARDS) $(OBJ_GAMEUI) -o $(EXEC) $(LDFLAGS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJ_MAIN) $(OBJ_COREMODUL) $(OBJ_CARDS) $(OBJ_GAMEUI) $(EXEC)

run: $(EXEC)
	./$(EXEC)

# Phony targets
.PHONY: all clean
