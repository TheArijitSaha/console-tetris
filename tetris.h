#ifndef TETRIS
#define TETRIS
#include "game_board.h"
#include "tet_block.h"

class Tetris {
	private:
		GameBoard board;
		bool game_over;
		TetBlock current_block;
		//void printGameOver();
	public:
		Tetris();
		~Tetris();
		
		/* Methhods */
		void loop();
		void formColours();
};

#endif /* TETRIS */

