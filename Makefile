# Compiler Info
CXX = g++

# Compiler flags
CXXFLAGS = -Wall
# Wall	: All warnings
# g			: For debugger

# Compiler libraries
CXXLIBS = -lncurses

# Directories:
ODIR = ./obj

.PHONY: clean

tetris_runner: tet_block.o game_board.o score_board.o tetris.o tetris_runner.o
	$(CXX) $(CXXFLAGS) -o $@ $(ODIR)/tetris_runner.o $(ODIR)/tetris.o $(ODIR)/score_board.o $(ODIR)/game_board.o $(ODIR)/tet_block.o $(CXXLIBS)

tetris_runner.o: tetris_runner.cpp tetris.h
	$(CXX) $(CXXFLAGS) -c tetris_runner.cpp -o $(ODIR)/$@ $(CXXLIBS)

tetris.o: tetris.cpp tetris.h game_board.h tet_block.h tetris_exceptions.h
	$(CXX) $(CXXFLAGS) -c tetris.cpp -o $(ODIR)/$@ $(CXXLIBS)

game_board.o: game_board.cpp game_board.h constants.h
	$(CXX) $(CXXFLAGS) -c game_board.cpp -o $(ODIR)/$@ $(CXXLIBS)

score_board.o: score_board.cpp score_board.h constants.h
	$(CXX) $(CXXFLAGS) -c score_board.cpp -o $(ODIR)/$@ $(CXXLIBS)

tet_block.o: tet_block.cpp tet_block.h constants.h tetris_exceptions.h
	$(CXX) $(CXXFLAGS) -c tet_block.cpp -o $(ODIR)/$@ $(CXXLIBS)

clean:
	rm -f $(ODIR)/*.o ./*.gch
