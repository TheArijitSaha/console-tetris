#ifndef STAT_BOARD
#define STAT_BOARD
#include "constants.hpp"
#include <ncurses.h>

class StatBoard {
	private:
		const int height, width;
		int tetrimino_frequency[TETRIMINO_COUNT];
		int total_tetrimino_count;
		WINDOW *stat_win;
	public:
		StatBoard();
		~StatBoard();

		/* Methods */
		void render();
		void createWindow(int, int);
		void incrementTetriminoFrequency(Tetrimino);
};

#endif /* STAT_BOARD */

