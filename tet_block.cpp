#include <iostream>
#include "tet_block.h"
#include <ctime>
//#include <stdlib.h>
//#include <conio.h>

using namespace std;

TetBlock::TetBlock(GameBoard* board) {
	srand(time(nullptr));
	this->board = board;
	//this->getNewBlock();
	//this->stamp();
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
													 None);
	}
}

/*bool TetBlock::isTouchingLeft()
{
		if(posY == 0) return true;//Reached the left vertical edge of board

		int i,j;
		for(i=0;i<=maxX;++i)
		{
				for(j=0;j<=maxY;++j)
				{
						if((bindedBoard->BoardMatrix[posX+i][posY+j-1] == FILLED_INT)&&(blockShape[i][j] == FILLED_INT)) return true;
						if(blockShape[i][j] == FILLED_INT) break;
				}
		}
		return false;
}

bool TetBlock::isTouchingRight()
{
		if(posY + maxY == BOARD_COLUMNS-1) return true;//Reached the vertical edge of board

		int i,j;
		for(i=0;i<=maxX;++i)
		{
				for(j=maxY;j>=0;--j)
				{
						if((bindedBoard->BoardMatrix[posX+i][posY+j+1] == FILLED_INT) && (blockShape[i][j] == FILLED_INT)) return true;
						if(blockShape[i][j] == FILLED_INT) break;
				}
		}
		return false;
}


bool TetBlock::isTouchingBelow()
{
		if(posX+maxX==BOARD_ROWS-1) return true;//Reached the floor of the board
		int i,j;
		for(j=0;j<=maxY;++j)
		{
				for(i=maxX;i>=0;--i)
				{
						if((bindedBoard->BoardMatrix[posX+i+1][posY+j] == FILLED_INT) && (blockShape[i][j] == FILLED_INT)) return true;
						if(blockShape[i][j] == FILLED_INT) break;
				}
		}
		return false;
}

bool TetBlock::isOverlapping()
{
		int i,j;
		for(i=0;i<=maxX;++i)
		{
				for(j=0;j<=maxY;++j)
				{
						if((bindedBoard->BoardMatrix[posX+i][posY+j] == FILLED_INT)&& (blockShape[i][j] == FILLED_INT)) return true;
				}
		}
		return false;
}*/

void TetBlock::readPattern() {
	this->height = this->width = 0;
	for (int i = 0; i < 4; ++i) {
		this->pattern[i] = block_pattern[this->block_index][this->orientation_index][i];
		this->width = max(this->width, this->pattern[i].X + 1);
		this->height = max(this->height, this->pattern[i].Y + 1);
	}
}

void TetBlock::getNewBlock() {
	this->block_index = rand() % BLOCK_COUNT;
	this->orientation_index = rand() % ORIENTATION_COUNT;
	this->colour = static_cast<CellColour>(this->block_index + 1);
	this->readPattern();
	this->Y = 0;
	this->X = (this->width > 2 ? 3 : 4);
}

/*void TetBlock::changeCurrentOrientation()
{
		int overlapX;
		int overlapY;
		int i,j;
		int oldPosX, oldPosY;
		int cnt = 0;
		unstamp();
		do
		{
				//store current position of the block
				oldPosX = posX;
				oldPosY = posY;
				//rotate the block
				orientation_index = (orientation_index+1)%ORIENTATION_COUNT;
				reSample();
				//reposition if out of bounds
				if(posY>BOARD_COLUMNS-1-maxY) posY=BOARD_COLUMNS-1-maxY;
				//reposition if overlapping
				overlapX = maxX+1;
				overlapY = maxY+1;

				for(i=0;i<=maxX;++i)
				{
						for(j=0;j<=maxY;++j)
						{
								if((bindedBoard->BoardMatrix[posX+i][posY+j] == FILLED_INT)&& (blockShape[i][j] == FILLED_INT))
								{
										if(i<overlapX) overlapX = i;
										if(j<overlapY) overlapY = j;
								}
						}
				}

				posX = posX-maxX-1+overlapX;
				posY = posY-maxY-1+overlapY;

				if(isOverlapping())//if still overlapping, revert back to the original position and try another orientation in the next loop run
				{
						posX=oldPosX;
						posY=oldPosY;
				}
				else//else stop rotating and exit this function
				{
						stamp();
						break;
				}
				++cnt;
		}while (cnt!=4);
}

void TetBlock::moveOneStepLeft()
{
		if(!isTouchingLeft())
		{
				unstamp();
				--posY;
				stamp();
		}
}
void TetBlock::moveOneStepRight()
{
		if(!isTouchingRight())
		{
				unstamp();
				++posY;
				stamp();
		}
}
void TetBlock::moveOneStepDown()
{
		if(!isTouchingBelow())
		{
				unstamp();
				++posX;
				stamp();
		}
}*/
