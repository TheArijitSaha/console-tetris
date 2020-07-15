#ifndef GAME_BOARD
#define GAME_BOARD
#include "constants.h"
#include <ncurses.h>

class GameBoard {
	private:
		int row_count, column_count, filled_height;
		Cell **board_matrix;
		BlockColour **board_colour_matrix;
		WINDOW *board_win;
		//int slashableAtRow[BOARD_ROWS];//stores 1 if ith row is slashable, else stores 0
		//bool isFilledRow(int i);//returns if its row is filled or not.
		//bool isSlashableRow(int i); //returns true if i'th row is slashable.
	public:
		GameBoard();
		~GameBoard();

		/* Getters */
		Cell getCell(int, int);
		int getRowCount();
		int getColumnCount();
		
		/* Setters */
		void setCell(int, int, Cell);
		void setColour(int, int, BlockColour);
		//int BoardColorMatrix[BOARD_ROWS][BOARD_COLUMNS];//stores color of each cell of the board
		//bool toBeSlashedNow;
		//void updateRoof();//updates the value of roof after a block is placed in the board;
		//void updateSlashIndices();//updates
		//void slashRows();

		/* Methods */
		void render();
		void createGameBoardWindow();
};

#endif /* GAME_BOARD */

