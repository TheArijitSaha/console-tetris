# Compiler Info
CXX = g++

# Compiler flags
CXXFLAGS = -Wall
# Wall	: All warnings
# g			: For debugger

# Compiler libraries
CXXLIBS = -lncursesw

# Directories:
ODIR = ./obj

.PHONY: clean

tetris_runner: tet_block.o game_board.o score_board.o stat_board.o tetris.o tetris_runner.o
	$(CXX) $(CXXFLAGS) -o $@ $(ODIR)/tetris_runner.o $(ODIR)/tetris.o $(ODIR)/score_board.o $(ODIR)/game_board.o $(ODIR)/stat_board.o $(ODIR)/tet_block.o $(CXXLIBS)

tetris_runner.o: tetris_runner.cpp tetris.hpp
	$(CXX) $(CXXFLAGS) -c tetris_runner.cpp -o $(ODIR)/$@ $(CXXLIBS)

tetris.o: tetris.cpp tetris.hpp game_board.hpp tet_block.hpp tetris_exceptions.hpp
	$(CXX) $(CXXFLAGS) -c tetris.cpp -o $(ODIR)/$@ $(CXXLIBS)

game_board.o: game_board.cpp game_board.hpp constants.hpp
	$(CXX) $(CXXFLAGS) -c game_board.cpp -o $(ODIR)/$@ $(CXXLIBS)

score_board.o: score_board.cpp score_board.hpp constants.hpp score_display.hpp
	$(CXX) $(CXXFLAGS) -c score_board.cpp -o $(ODIR)/$@ $(CXXLIBS)

stat_board.o: stat_board.cpp stat_board.hpp constants.hpp
	$(CXX) $(CXXFLAGS) -c stat_board.cpp -o $(ODIR)/$@ $(CXXLIBS)

tet_block.o: tet_block.cpp tet_block.hpp constants.hpp tetris_exceptions.hpp
	$(CXX) $(CXXFLAGS) -c tet_block.cpp -o $(ODIR)/$@ $(CXXLIBS)

clean:
	rm -f $(ODIR)/*.o
