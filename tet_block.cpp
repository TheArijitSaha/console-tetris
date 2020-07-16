#include <iostream>
#include "tet_block.h"
#include <ctime>

using namespace std;

TetBlock::TetBlock(GameBoard* board) {
	srand(time(nullptr));
	this->board = board;
}

/* Sensory Methods */
bool TetBlock::isTouchingBelow() {
	if (this->Y + this->height >= this->board->getRowCount()) return true;
	this->unstamp();
	for (int i = 0; i < 4; ++i) {
		if (this->board->getCell(this->X + this->pattern[i].X, this->Y + this->pattern[i].Y + 1) == Full) {
			this->stamp();
			return true;
		}
	}
	this->stamp();
	return false;
}

bool TetBlock::isTouchingLeft() {
	if (this->X == 0) return true;
	this->unstamp();
	for (int i = 0; i < 4; ++i) {
		if (this->board->getCell(this->X + this->pattern[i].X - 1, this->Y + this->pattern[i].Y) == Full) {
			this->stamp();
			return true;
		}
	}
	this->stamp();
	return false;
}

bool TetBlock::isTouchingRight() {
	if (this->X + this->width >= this->board->getColumnCount()) return true;
	this->unstamp();
	for (int i = 0; i < 4; ++i) {
		if (this->board->getCell(this->X + this->pattern[i].X + 1, this->Y + this->pattern[i].Y) == Full) {
			this->stamp();
			return true;
		}
	}
	this->stamp();
	return false;
}

bool TetBlock::isOverlapping() {
	for (int i = 0; i < 4; ++i) {
		if (this->board->getCell(this->X + this->pattern[i].X, this->Y + this->pattern[i].Y) == Full) {
			return true;
		}
	}
	return false;
}

bool TetBlock::isOutOfBounds() {
	for (int i = 0; i < 4; ++i) {
		if ((this->X + this->pattern[i].X >= this->board->getColumnCount())
				|| (this->X + this->pattern[i].X < 0)
				|| (this->Y + this->pattern[i].Y >= this->board->getRowCount())
				|| (this->Y + this->pattern[i].Y < 0)) {
			return true;
		}
	}
	return false;
}

/* Movement methods */
void TetBlock::moveOneStepDown() {
	if (!this->isTouchingBelow()) {
		this->unstamp();
		++(this->Y);
		this->stamp();
	}
}

void TetBlock::moveOneStepLeft() {
	if (!this->isTouchingLeft()) {
		this->unstamp();
		--(this->X);
		this->stamp();
	}
}

void TetBlock::moveOneStepRight() {
	if (!this->isTouchingRight()) {
		this->unstamp();
		++(this->X);
		this->stamp();
	}
}

void TetBlock::changeOrientation() {
	int previous_orientation = this->orientation_index;
	int previous_X = this->X;
	int previous_Y = this->Y;
	int previous_height = this->height;
	int previous_width = this->width;

	unstamp();
	for (int i = 1; i < 4; ++i) {
		// rotate
		this->orientation_index = (this->orientation_index + i) % ORIENTATION_COUNT;
		this->readPattern();

		// fix position
		this->X = previous_X + (previous_width - this->width) / 2;
		this->Y = previous_Y + (previous_height - this->height) / 2;

		// try on
		if ((this->isOutOfBounds()) || (this->isOverlapping())) {
			continue;
		}

		stamp();
		return;
		// if possible update orientation index and break
		// do
		// {
		// 		//store current position of the block
		// 		oldPosX = posX;
		// 		oldPosY = posY;
		// 		//rotate the block
		// 		orientation_index = (orientation_index+1)%ORIENTATION_COUNT;
		// 		reSample();
		// 		//reposition if out of bounds
		// 		if(posY>BOARD_COLUMNS-1-maxY) posY=BOARD_COLUMNS-1-maxY;
		// 		//reposition if overlapping
		// 		overlapX = maxX+1;
		// 		overlapY = maxY+1;

		// 		for(i=0;i<=maxX;++i)
		// 		{
		// 				for(j=0;j<=maxY;++j)
		// 				{
		// 						if((bindedBoard->BoardMatrix[posX+i][posY+j] == FILLED_INT)&& (blockShape[i][j] == FILLED_INT))
		// 						{
		// 								if(i<overlapX) overlapX = i;
		// 								if(j<overlapY) overlapY = j;
		// 						}
		// 				}
		// 		}

		// 		posX = posX-maxX-1+overlapX;
		// 		posY = posY-maxY-1+overlapY;
	}
	this->X = previous_X;
	this->Y = previous_Y;
	this->orientation_index = previous_orientation;
	this->readPattern();
	stamp();
}

/* Functionality Methods */
void TetBlock::getNewBlock() {
	this->block_index = rand() % BLOCK_COUNT;
	this->orientation_index = rand() % ORIENTATION_COUNT;
	this->colour = static_cast<BlockColour>(this->block_index + 1);
	this->readPattern();
	this->Y = 0;
	this->X = (this->board->getColumnCount() - this->width) / 2;
	this->stamp();
}

void TetBlock::readPattern() {
	this->height = this->width = 0;
	for (int i = 0; i < 4; ++i) {
		this->pattern[i] = block_pattern[this->block_index][this->orientation_index][i];
		this->width = max(this->width, this->pattern[i].X + 1);
		this->height = max(this->height, this->pattern[i].Y + 1);
	}
}

void TetBlock::stamp() {
	for (int i = 0; i < 4; ++i) {
		this->board->setCell(this->X + this->pattern[i].X,
												 this->Y + this->pattern[i].Y,
												 Full);
		this->board->setColour(this->X + this->pattern[i].X,
													 this->Y + this->pattern[i].Y,
													 this->colour);
	}
}

void TetBlock::unstamp() {
	for (int i = 0; i < 4; ++i) {
		this->board->setCell(this->X + this->pattern[i].X,
												 this->Y + this->pattern[i].Y,
												 Empty);
		this->board->setColour(this->X + this->pattern[i].X,
													 this->Y + this->pattern[i].Y,
													 BLOCK_NONE);
	}
}

