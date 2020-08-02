#ifndef TET_BLOCK
#define TET_BLOCK
#include "game_board.hpp"
#include "tetris_exceptions.hpp"

class TetBlock {
	private:
		Point pattern[4];
		GameBoard *board;
		int X, Y, width, height;
		Tetrimino block_index;
		int orientation_index;
		BlockColour colour;
	public:
		TetBlock(GameBoard*);

		/* Getters */
		Tetrimino getTetriminoTag();

		/* Sensory Methods */
		bool isTouchingLeft();
		bool isTouchingRight();
		bool isTouchingBelow();
		bool isOutOfBounds();
		bool isOverlapping();

		/* Movement Methods */
		void moveOneStepDown();
		void moveOneStepLeft();
		void moveOneStepRight();
		void changeOrientation();
		
		/* Functionality Methods */
		void getNewBlock();
		void readPattern();
		void stamp();
		void unstamp();
};

#endif /* TET_BLOCK */

