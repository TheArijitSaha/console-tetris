#ifndef SCORE_BOARD
#define SCORE_BOARD
#include "constants.hpp"
#include <ncursesw/ncurses.h>

class ScoreBoard {
	private:
		const int height, width;
		int rendered_score;
		WINDOW *score_win;
	public:
		ScoreBoard();
		~ScoreBoard();

		/* Methods */
		void render();
		void createWindow(int, int);
		void update(int);
};

#endif /* SCORE_BOARD */

