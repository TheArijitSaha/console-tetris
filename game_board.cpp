#include <iostream>
#include "game_board.h"

using namespace std;

GameBoard::GameBoard() {
	this->board_win = nullptr;
	this->row_count = BOARD_ROWS;
	this->column_count = BOARD_COLUMNS;

	this->board_matrix = (Cell**) malloc(sizeof(Cell*) * this->row_count);
	this->board_colour_matrix = (BlockColour**) malloc(sizeof(BlockColour*) * this->row_count);
	for (int i = 0; i < this->row_count; ++i) {
		this->board_matrix[i] = (Cell*) malloc(sizeof(Cell) * this->column_count);
		this->board_colour_matrix[i] = (BlockColour*) malloc(sizeof(BlockColour) * this->column_count);
		for (int j = 0; j < this->column_count; ++j) {
			this->board_matrix[i][j] = Empty;
			this->board_colour_matrix[i][j] = BLOCK_NONE;
		}
		// slashableAtRow[i] = 0;
	}
	this->filled_height = 0;
	// toBeSlashedNow = false;
}

GameBoard::~GameBoard() {
	if (this->board_win != nullptr) {
		delwin(this->board_win);
	}
}

/* Getters */
Cell GameBoard::getCell(int X, int Y) {
	if ((X < 0) || (X >= this->column_count) || (Y < 0) || (Y >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid cell Coordinates (%d, %d)\n", X, Y);
		exit(EXIT_FAILURE);
	}

	return this->board_matrix[Y][X];
}

int GameBoard::getRowCount() {
	return this->row_count;
}

int GameBoard::getColumnCount() {
	return this->column_count;
}

/* Setters */
void GameBoard::setCell(int X, int Y, Cell val) {
	if ((X < 0) || (X >= this->column_count) || (Y < 0) || (Y >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid cell Coordinates (%d, %d)\n", X, Y);
		exit(EXIT_FAILURE);
	}

	this->board_matrix[Y][X] = val;
}

void GameBoard::setColour(int X, int Y, BlockColour val) {
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

/* Methods */
void GameBoard::render() {
	wclear(this->board_win);
	for (int i = 0; i < this->row_count; ++i) {
		wmove(this->board_win, i, 0);
		for (int j = 0; j < this->column_count; ++j) {
			if (this->board_matrix[i][j] == Empty) {
				if ((i + j) % 2 == 0) {
					wattron(this->board_win, COLOR_PAIR(BLOCK_BG1));
				} else {
					wattron(this->board_win, COLOR_PAIR(BLOCK_BG2));
				}
				wprintw(this->board_win, "  ");
				if ((i + j) % 2 == 0) {
					wattroff(this->board_win, COLOR_PAIR(BLOCK_BG1));
				} else {
					wattroff(this->board_win, COLOR_PAIR(BLOCK_BG2));
				}
			} else {
				wattron(this->board_win, COLOR_PAIR(this->board_colour_matrix[i][j]));
				wprintw(this->board_win, "  ");
				wattroff(this->board_win, COLOR_PAIR(this->board_colour_matrix[i][j]));
			}
		}
	}
	wrefresh(this->board_win);
}

void GameBoard::createGameBoardWindow() {
	if (this->board_win != nullptr) {	// Already initialised
		return;
	}
	int starty = (LINES - this->row_count) / 2;
	int startx = (COLS - this->column_count * 2) / 2;
	this->board_win = newwin(this->row_count, this->column_count * 2, starty, startx);
	wrefresh(this->board_win);
}
