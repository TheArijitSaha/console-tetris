#ifndef TETRIS
#define TETRIS
#include "game_board.h"
#include "score_board.h"
#include "tet_block.h"

class Tetris {
	private:
		GameBoard game_board;
		ScoreBoard score_board;
		bool game_over;
		TetBlock current_block;
		int line_clears, score;
	public:
		Tetris();
		~Tetris();

		/* Getters */
		int getNumberOfLineClears();
		int getLevel();
		int getScore();
		
		/* Methods */
		void loop();
		void formColours();
};

#endif /* TETRIS */

