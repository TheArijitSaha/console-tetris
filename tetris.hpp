#ifndef TETRIS
#define TETRIS
#include "game_board.hpp"
#include "score_board.hpp"
#include "tet_block.hpp"

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

