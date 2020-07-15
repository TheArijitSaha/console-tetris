#ifndef TETRIS
#define TETRIS
#include "game_board.h"
#include "tet_block.h"

class Tetris {
	private:
		GameBoard board;
		bool game_over;
		TetBlock current_block;
		//char pressed_key;
		//void slashRoutine();
		//void printGameOver();
	public:
		Tetris();
		~Tetris();
		void loop();
		void formColours();
};

#endif /* TETRIS */
