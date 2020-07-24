#include <iostream>
#include "score_board.h"

using namespace std;

ScoreBoard::ScoreBoard(): height(4), width(5 * 6) {
	this->score_win = nullptr;
}

ScoreBoard::~ScoreBoard() {
	if (this->score_win != nullptr) {
		delwin(this->score_win);
	}
}

/* Methods */
void ScoreBoard::render() {
	werase(this->score_win);
	wrefresh(this->score_win);
}

void ScoreBoard::createWindow(int screen_height, int screen_width) {
	if (this->score_win != nullptr) {	// Already initialised
		return;
	}
	int starty = (screen_height - this->height) / 2;
	int startx = (screen_width - this->width) / 4;
	this->score_win = newwin(this->height, this->width, starty, startx);
	wbkgdset(this->score_win, COLOR_PAIR(BLOCK_BG1));
	wrefresh(this->score_win);
}

