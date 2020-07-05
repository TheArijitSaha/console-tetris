# Compiler Info
CXX = g++

# Compiler flags
CXXFLAGS = -Wall
# Wall	: All warnings
# g			: For debugger

# Directories:
ODIR = ./obj

tetris_runner: tetris_runner.o tetris.o game_board.o
	$(CXX) $(CXXFLAGS) -o tetris_runner $(ODIR)/tetris_runner.o $(ODIR)/tetris.o $(ODIR)/game_board.o

tetris_runner.o: tetris_runner.cpp tetris.h
	$(CXX) $(CXXFLAGS) -c tetris_runner.cpp -o $(ODIR)/$@

tetris.o: tetris.cpp tetris.h game_board.h
	$(CXX) $(CXXFLAGS) -c tetris.cpp -o $(ODIR)/$@

game_board.o: game_board.cpp game_board.h constants.h
	$(CXX) $(CXXFLAGS) -c game_board.cpp -o $(ODIR)/$@

clean:
	rm -f $(ODIR)/*.o ./*.gch
