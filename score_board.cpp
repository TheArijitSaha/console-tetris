#define _XOPEN_SOURCE_EXTENDED

#include <iostream>
#include "score_board.hpp"
#include "score_display.hpp"

using namespace std;

ScoreBoard::ScoreBoard(): height(3), width(5 * 6) {
	this->score_win = nullptr;
	this->rendered_score = 0;
}

ScoreBoard::~ScoreBoard() {
	if (this->score_win != nullptr) {
		delwin(this->score_win);
	}
}

/* Methods */
void ScoreBoard::render() {
	werase(this->score_win);
	mvwaddstr(this->score_win, 0, 0, number_pattern[0][0]);
	mvwaddstr(this->score_win, 1, 0, number_pattern[0][1]);
	mvwaddstr(this->score_win, 2, 0, number_pattern[0][2]);
	//wattron(this->score_win, COLOR_PAIR(BLOCK_RED));
	//wattroff(this->score_win, COLOR_PAIR(BLOCK_RED));
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

void ScoreBoard::update(int new_score) {
	if (this->rendered_score != new_score) {
		this->rendered_score = new_score;
		this->render();
	}
}

