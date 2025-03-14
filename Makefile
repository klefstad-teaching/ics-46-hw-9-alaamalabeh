# Compiler and Flags
CXX = g++
CXX_FLAGS = -std=c++17 -I src

# Executable Names
DIJKSTRA_EXE = dijkstra_main
LADDER_EXE = ladder_main

all: $(DIJKSTRA_EXE) $(LADDER_EXE)

# Link Dijkstra's final executable
$(DIJKSTRA_EXE): src/dijkstras_main.cpp src/dijkstras.o
	$(CXX) $(CXX_FLAGS) src/dijkstras_main.cpp src/dijkstras.o -o $(DIJKSTRA_EXE)

# Compile dijkstra.cpp into dijkstras.o
src/dijkstras.o: src/dijkstras.cpp src/dijkstras.h
	$(CXX) $(CXX_FLAGS) -c src/dijkstras.cpp -o src/dijkstras.o

# Link Word Ladder final executable
$(LADDER_EXE): src/ladder_main.cpp src/ladder.o
	$(CXX) $(CXX_FLAGS) src/ladder_main.cpp src/ladder.o -o $(LADDER_EXE)

# Compile ladder.cpp into ladder.o
src/ladder.o: src/ladder.cpp src/ladder.h
	$(CXX) $(CXX_FLAGS) -c src/ladder.cpp -o src/ladder.o

clean:
	rm -f src/*.o $(DIJKSTRA_EXE) $(LADDER_EXE)
