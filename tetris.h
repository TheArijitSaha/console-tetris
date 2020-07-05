#ifndef TETRIS
#define TETRIS
#include "game_board.h"
#include <ctime>

class Tetris {
	private:
		gameBoard board;
		bool gameOver;
		//TetBlock currentBlock;
		//clock_t t1,t2;
		//HANDLE currentHandle;
		//char pressed_key;
		//void slashRoutine();
		//void printGameOver();
	public:
		Tetris();
		void initialise();
		void loop();
};

#endif /* TETRIS */
