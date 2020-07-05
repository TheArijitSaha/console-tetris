# Compiler Info
CXX = g++

# Compiler flags
CXXFLAGS = -Wall
# Wall	: All warnings
# g			: For debugger

runner: runner.o tetris.o game_board.o
	$(CXX) $(CXXFLAGS) -o runner runner.o tetris.o game_board.o

runner.o: runner.cpp tetris.h
	$(CXX) $(CXXFLAGS) -c runner.cpp

tetris.o: tetris.cpp tetris.h game_board.h
	$(CXX) $(CXXFLAGS) -c tetris.cpp

game_board.o: game_board.cpp game_board.h
	$(CXX) $(CXXFLAGS) -c game_board.cpp
