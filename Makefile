# Compiler Info
CXX = g++

# Compiler flags
CXXFLAGS = -Wall
# Wall	: All warnings
# g			: For debugger

# Directories:
ODIR = ./obj

.PHONY: clean

tetris_runner: tet_block.o game_board.o tetris.o tetris_runner.o
	$(CXX) $(CXXFLAGS) -o $@ $(ODIR)/tetris_runner.o $(ODIR)/tetris.o $(ODIR)/game_board.o $(ODIR)/tet_block.o

tetris_runner.o: tetris_runner.cpp tetris.h
	$(CXX) $(CXXFLAGS) -c tetris_runner.cpp -o $(ODIR)/$@

tetris.o: tetris.cpp tetris.h game_board.h tet_block.h
	$(CXX) $(CXXFLAGS) -c tetris.cpp -o $(ODIR)/$@

game_board.o: game_board.cpp game_board.h constants.h
	$(CXX) $(CXXFLAGS) -c game_board.cpp -o $(ODIR)/$@

tet_block.o: tet_block.cpp tet_block.h constants.h
	$(CXX) $(CXXFLAGS) -c tet_block.cpp -o $(ODIR)/$@

clean:
	rm -f $(ODIR)/*.o ./*.gch
