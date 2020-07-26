#ifndef SCORE_BOARD
#define SCORE_BOARD
#include "constants.hpp"
#include <ncursesw/ncurses.h>
#include <string>

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

		/* Static Methods */
		static std::string getIntegerAsPaddedString(int, int);
};

#endif /* SCORE_BOARD */

