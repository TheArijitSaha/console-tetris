#define _XOPEN_SOURCE_EXTENDED

#include <string>
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
	string padded_score = this->getIntegerAsPaddedString(this->rendered_score, 6);
	//wattron(this->score_win, COLOR_PAIR(BLOCK_RED));
	for (int line = 0; line < 3; ++line) {
		wmove(this->score_win, line, 0);
		for (char number: padded_score) {
			waddwstr(this->score_win, number_pattern[number - '0'][line]);
		}
	}
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

/* Static Methods */
string ScoreBoard::getIntegerAsPaddedString(int number, int pad_length) {
	string reverse_padded_string = "", padded_string = "";

	for (int i = 0; i < pad_length; ++i) {
		reverse_padded_string += (char) ((number % 10) + '0');
		number /= 10;
	}
	
	for (int i = 0; i < pad_length; ++i) {
		padded_string += reverse_padded_string[pad_length - 1 - i];
	}

	return padded_string;
}

