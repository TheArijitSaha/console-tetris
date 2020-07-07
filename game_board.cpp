#include <iostream>
#include "game_board.h"
//#include <time.h>
//#include <stdlib.h>
//#include <conio.h>

using namespace std;

/* -- */ GameBoard::GameBoard() {
	this->row_count = BOARD_ROWS;
	this->column_count = BOARD_COLUMNS;
	this->board_matrix = (Cell**) malloc(sizeof(Cell*) * this->row_count);
	this->board_colour_matrix = (CellColour**) malloc(sizeof(CellColour*) * this->row_count);
	for (int i = 0; i < this->row_count; ++i) {
		this->board_matrix[i] = (Cell*) malloc(sizeof(Cell) * this->column_count);
		this->board_colour_matrix[i] = (CellColour*) malloc(sizeof(CellColour) * this->column_count);
		for (int j = 0; j < this->column_count; ++j) {
			this->board_matrix[i][j] = Empty;
			this->board_colour_matrix[i][j] = None;
		}
		// slashableAtRow[i] = 0;
	}
	this->filled_height = 0;
	// toBeSlashedNow = false;
}

/* -- */ void GameBoard::render() {
	this->erase();
	for (int k = 0; k < 8; ++k) printf("\n");	/* TODO */
	for (int i = 0; i < this->row_count; ++i) {
		for (int k = 0; k < 7; ++k) printf("\t");	/* TODO */
		for (int j = 0; j < this->column_count; ++j) {
			if (this->board_matrix[i][j] == Empty) {
				printf("%s  %s", COLOUR_BG[(i + j) % 2], COLOUR_RESET);
			} else {
				printf("%s  %s", COLOUR_CELL[this->board_colour_matrix[i][j]], COLOUR_RESET);
			}
		}
		printf("\n");
	}
}

void GameBoard::erase() {
	system("clear");
}

void GameBoard::setCell(int X, int Y, Cell val) {
	this->board_matrix[Y][X] = val;
}

void GameBoard::setColour(int X, int Y, CellColour val) {
 this->board_colour_matrix[Y][X] = val;
}

/* -- */ /*bool GameBoard::isFilledRow(int i)
{
		int j;
		for(j=0;j<BOARD_COLUMNS;++j)
		{
				if(BoardMatrix[i][j] == FILLED_INT) return true;
		}
		return false;
}*/

/*bool GameBoard::isSlashableRow(int i)
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
}*/
