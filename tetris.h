#ifndef TETRIS
#define TETRIS
#include "game_board.h"
#include "tet_block.h"

class Tetris {
	private:
		GameBoard board;
		bool game_over;
		TetBlock current_block;
	public:
		Tetris();
		~Tetris();
		
		/* Methods */
		void loop();
		void formColours();
};

#endif /* TETRIS */

