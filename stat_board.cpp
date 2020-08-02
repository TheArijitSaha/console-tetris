#include "stat_board.hpp"
#include "constants.hpp"

using namespace std;

StatBoard::StatBoard(): height(3 * TETRIMINO_COUNT), width(4 * 2 + 4 + 7) {
	this->stat_win = nullptr;
	this->total_tetrimino_count = 0;

	for (int i = 0; i < TETRIMINO_COUNT; ++i) {
		this->tetrimino_frequency[i] = 0;
	}
}

StatBoard::~StatBoard() {
	if (this->stat_win != nullptr) {
		delwin(this->stat_win);
	}
}

/* Methods */
void StatBoard::render() {
	werase(this->stat_win);
	int tetrimino_orientation[TETRIMINO_COUNT] = {3, 0, 1, 0, 0, 0, 0};

	for (int stat_tet = 0; stat_tet < TETRIMINO_COUNT; ++stat_tet) {
		int pos_y = stat_tet * 3 + 1, pos_x = 0;

		wmove(this->stat_win, pos_y, pos_x);
		wattron(this->stat_win, COLOR_PAIR(stat_tet + 1));

		for (int i = 0; i < 4; ++i) {
			mvwprintw(this->stat_win,
								pos_y + block_pattern[stat_tet][tetrimino_orientation[stat_tet]][i].Y,
								pos_x + block_pattern[stat_tet][tetrimino_orientation[stat_tet]][i].X * 2,
								"  ");
		}

		wattroff(this->stat_win, COLOR_PAIR(stat_tet));
	}
	
	for (int stat_tet = 0; stat_tet < TETRIMINO_COUNT; ++stat_tet) {
		wmove(this->stat_win, stat_tet * 3 + 1, 4 * 2 + 1);
		wattron(this->stat_win, COLOR_PAIR(STAT));

		if (this->total_tetrimino_count == 0) {
			wprintw(this->stat_win, "--   0.0 %%");
		} else {
			wprintw(this->stat_win, "-- %5.1f %%", (this->tetrimino_frequency[stat_tet] / (float)this->total_tetrimino_count) * 100);
		}

		wattroff(this->stat_win, COLOR_PAIR(STAT));
	}

	wrefresh(this->stat_win);
}

void StatBoard::createWindow(int screen_height, int screen_width) {
	if (this->stat_win != nullptr) {	// Already initialised
		return;
	}
	int starty = (screen_height - this->height) / 2;
	int startx = ((screen_width - this->width) * 3) / 4;

	this->stat_win = newwin(this->height, this->width, starty, startx);
	wattrset(this->stat_win, A_NORMAL);
	wbkgdset(this->stat_win, COLOR_PAIR(STAT));
	box(this->stat_win, 0, 0);
	wrefresh(this->stat_win);
	this->render();
}

void StatBoard::incrementTetriminoFrequency(Tetrimino tet) {
	if ((tet >= TETRIMINO_COUNT) || (tet < 0)) return;

	++(this->tetrimino_frequency[tet]);
	++(this->total_tetrimino_count);

	this->render();
}

