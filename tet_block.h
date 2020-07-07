#ifndef TET_BLOCK
#define TET_BLOCK
#include "game_board.h"

class TetBlock {
	private:
		GameBoard *board;
		int X, Y, width, height;
		int block_index, orientation_index;
		Point pattern[4];
		CellColour colour;
	public:
		TetBlock(GameBoard*);
		// int blockShape[4][4];//stores the shape of block in 2D matrix form, represented by 0/1
		// int maxX,maxY;//stores max range of the block in blockShape Matrix
		// int blockColor;
		// TetBlock(GameBoard *gb);//Constructor
		// void bindWithBoard(GameBoard *gb);

		void getNewBlock();
		void readPattern();
		void stamp();
		void unstamp();
		// void changeCurrentOrientation();//Rotate the current block assigned to this TetBlock

		// ///SENSING METHODS
		// bool isTouchingLaterally();//is this block touching board or other block vertically??
		// bool isTouchingLeft();//left edge of this block touching anything?
		// bool isTouchingRight();//right edge of this block touching anything?
		// bool isTouchingBelow();//Base of this block touching anything?
		// bool isOverlapping();//Block overlapping with existing blocks?


		// ///MOVEMENT METHODS
		// void moveOneStepDown();
		// void moveOneStepLeft();
		// void moveOneStepRight();

};

#endif /* TET_BLOCK */
