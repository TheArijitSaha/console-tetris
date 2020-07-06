#ifndef GAME_BOARD
#define GAME_BOARD

class gameBoard {
	private:
		int row_count, column_count;
		//int slashableAtRow[BOARD_ROWS];//stores 1 if ith row is slashable, else stores 0
		//bool isFilledRow(int i);//returns if its row is filled or not.
		//bool isSlashableRow(int i); //returns true if i'th row is slashable.
	public:
		gameBoard();
		void render();
		void erase();
		//int BoardMatrix[BOARD_ROWS][BOARD_COLUMNS];//stores EMPTY_INT or FILLED_INT
		//int BoardColorMatrix[BOARD_ROWS][BOARD_COLUMNS];//stores color of each cell of the board
		//int roof;//stores the index of first empty row from the bottom of the board.
		//bool toBeSlashedNow;
		//void updateRoof();//updates the value of roof after a block is placed in the board;
		//void updateSlashIndices();//updates
		//void slashRows();
};

//void initializeBlockMatrix();
#endif /* GAME_BOARD */
