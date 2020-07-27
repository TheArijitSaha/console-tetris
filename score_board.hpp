#ifndef SCORE_BOARD
#define SCORE_BOARD
#include "constants.hpp"
#include <ncursesw/ncurses.h>
#include <string>

class ScoreBoard {
	private:
		const int height, width;
		int rendered_score, rendered_level;
		WINDOW *score_win;
	public:
		ScoreBoard();
		~ScoreBoard();

		/* Methods */
		void render();
		void createWindow(int, int);
		void update(int, int);

		/* Static Methods */
		static std::string getIntegerAsPaddedString(int, int);
		static int getNoOfDigitsInInteger(int);
};

#endif /* SCORE_BOARD */

