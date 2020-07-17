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

		// Correct out of bounds in horizontal axis
		this->X = max(0, this->X);
		this->X = min(this->board->getColumnCount() - this->width, this->X);

		// Correct out of bounds in vertical axis
		/* While performing Y-axis correction, the block should not be
		 * pushed upwards, otherwise this can result in the player
		 * doing so repeatedly to keep an I-block from reaching the floor.
		 * So, only downward adjustment is done.
		 */
		this->Y = max(0, this->Y);

		// Correct overlapping in horizontal axis
		/* This loop checks if the block is overlapping with another block,
		 * If yes, it goes onto check if positions X + 1, X - 1, X + 2, X - 2
		 * are compatible (in that particular order) and breaks whenever no
		 * overlapping is found.
		 * If none of the five positions (including the one calculated originally)
		 * are compatible, then this orientation is not possible.
		 */
		for (i = 1; i <= 4; ++i) {
			if ((!this->isOutOfBounds()) && (!this->isOverlapping())) break;

			/* The following if-else generates the next relative positions in
			 * this order as the loop iterates:
			 *     +1, -1, +2, -2
			 */
			if (i % 2 == 1) {
				this->X += i;
			} else {
				this->X -= i;
			}
		}

		if ((this->isOutOfBounds()) || (this->isOverlapping())) {
			continue;
		}

		stamp();
		return;
	}

	// If no rotated orientation works, stamp original position itself
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

