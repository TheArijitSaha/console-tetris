#ifndef SCORE_BOARD
#define SCORE_BOARD
#include "constants.h"
#include <ncurses.h>

class ScoreBoard {
	private:
		const int height, width;
		WINDOW *score_win;
	public:
		ScoreBoard();
		~ScoreBoard();

		/* Methods */
		void render();
		void createWindow(int, int);
};

#endif /* SCORE_BOARD */

