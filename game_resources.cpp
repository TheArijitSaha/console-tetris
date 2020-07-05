#include <iostream>
#include "game_resources.h"
//#include <time.h>
//#include <stdlib.h>
//#include <conio.h>

using namespace std;

gameBoard::gameBoard() {
	this.row_count = 0;
	this.column_count = 0;
	/*int i, j;
	//initialize game board with all cells as EMPTY_INT (0)
	for(i=0;i<BOARD_ROWS;++i)
	{
		for(j=0;j<BOARD_COLUMNS;++j)
		{
			BoardMatrix[i][j] = EMPTY_INT;
			BoardColorMatrix[i][j] = WHITE;
		}
		slashableAtRow[i] = 0;
	}
	//initialize roof
	roof = BOARD_ROWS-1;
	toBeSlashedNow = false;*/
}

void gameBoard::render() {
	for (int i = 0; i < this.row_count; ++i) {
		for (int j = 0; j < this.column_count; ++j) {
			// if(BoardMatrix[i][j] == EMPTY_INT) cout<<EMPTY_CHAR;
			// else
			// {
			// 	SetConsoleTextAttribute(h,BoardColorMatrix[i][j]);//SET TEXT COLOR TO COLOR OF CURRENT CELL
			// 	cout<<FILLED_CHAR;
			// 	SetConsoleTextAttribute(h,WHITE);//RESET TEXT COLOR TO WHITE
			// }
		}
		cout<"Rendered\n";
		cout<<'\n';
	}
}

/*void GameBoard::eraseBoard()
{
		system("cls");
}

bool GameBoard::isFilledRow(int i)
{
		int j;
		for(j=0;j<BOARD_COLUMNS;++j)
		{
				if(BoardMatrix[i][j] == FILLED_INT) return true;
		}
		return false;
}

bool GameBoard::isSlashableRow(int i)
{
		int j;
		for(j=0;j<BOARD_COLUMNS;++j)
		{
				if(BoardMatrix[i][j] == EMPTY_INT) return false;
		}
		return true;
}

void GameBoard::updateRoof()
{
		while(roof>=0 && isFilledRow(roof)) --roof;
}

void GameBoard::updateSlashIndices()
{
		int i;
		for(i=roof+1;i<BOARD_ROWS;++i)
		{
				if(isSlashableRow(i))
				{
						slashableAtRow[i] = 1;
						toBeSlashedNow = true;
				}
		}
}

void GameBoard::slashRows()
{
		if( !toBeSlashedNow) return;

		toBeSlashedNow=false;//Reset toBeSlashedNow for the next run
		int i1,i2,j;
		int tempRoof = roof;
		i1=i2=BOARD_ROWS-1;
		while(i2>roof && i1>roof)
		{
				while(slashableAtRow[i2])//slash off adjacent rows...
				{
						slashableAtRow[i2]=0;//reset the slash index array.
						//for(j=0;j<BOARD_COLUMNS;++j)
						//{
								//reset i2 row
						//		BoardMatrix[i2][j] = EMPTY_CHAR;
						//		BoardColorMatrix[i2][j]=WHITE;
						//}
						--i2;
						++tempRoof;//roof goes down for each slash
				}
				//Bring down rest of the blocks
				if(i1!=i2 && i2>roof)
				{
						for(j=0;j<BOARD_COLUMNS;++j)
						{
								//copy from i2 to i1 row
								BoardMatrix[i1][j]=BoardMatrix[i2][j];
								BoardColorMatrix[i1][j]=BoardColorMatrix[i2][j];
								//reset i2 row
							 // BoardMatrix[i2][j] = EMPTY_CHAR;
							//	BoardColorMatrix[i2][j]=WHITE;
						}
				}
				--i1;
				--i2;
		}
		while(i1>roof)
		{
				for(j=0;j<BOARD_COLUMNS;++j)
				{
						BoardMatrix[i1][j] = EMPTY_INT;
						BoardColorMatrix[i1][j]=WHITE;
				}
				--i1;
		}
		roof = tempRoof;//update roof
}
///TETBLOCK
TetBlock::TetBlock()
{

}
TetBlock::TetBlock(GameBoard *gb)
{
		bindedBoard = gb;
		sampleRandomBlock();
}
void TetBlock::bindWithBoard(GameBoard *gb)
{
		bindedBoard = gb;
		sampleRandomBlock();
		stamp();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TetBlock::stamp()
{
		int i,j;
		for(i=0;i<=maxX;++i)
		{
				for(j=0;j<=maxY;++j)
				{
						if(blockShape[i][j] == FILLED_INT)
						{
								bindedBoard->BoardMatrix[posX+i][posY+j] = FILLED_INT;
								bindedBoard->BoardColorMatrix[posX+i][posY+j] = blockColor;
						}
				}
		}
}

void TetBlock::unstamp()
{
		int i,j;
		for(i=0;i<=maxX;++i)
		{
				for(j=0;j<=maxY;++j)
				{
						if(blockShape[i][j] == FILLED_INT)
						{
								bindedBoard->BoardMatrix[posX+i][posY+j] = EMPTY_INT;
								bindedBoard->BoardColorMatrix[posX+i][posY+j] = WHITE;
						}
				}
		}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool TetBlock::isTouchingLeft()
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
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TetBlock::reSample()
{
		maxX=maxY=0;
		int i,j;
		for(i=0;i<4;++i)
		{
				for(j=0;j<4;++j)
				{
						blockShape[i][j] = blockMatrix[4*block_index+i][4*orientation_index + j];
						if(blockShape[i][j] == FILLED_INT)
						{
								if(i>maxX) maxX = i;
								if(j>maxY) maxY = j;
						}
				}
		}
}
void TetBlock::sampleRandomBlock()
{
		posX = 0;
		srand (time(NULL));

		block_index = rand()%BLOCK_COUNT;
		orientation_index = rand()%ORIENTATION_COUNT;

		blockColor = validColorList[rand()%REDUCED_COLOR_RANGE];

		reSample();
		posY = rand()%(BOARD_COLUMNS-maxY);
}

void TetBlock::changeCurrentOrientation()
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
