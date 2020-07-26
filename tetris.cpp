#include "tetris.hpp"
#include "tetris_exceptions.hpp"
#include <cstdlib>
#include <unistd.h>
#include <locale.h>
#include <ctime>
#include <ncurses.h>

using namespace std;

Tetris::Tetris(): game_board(), score_board(), current_block(&(this->game_board)) {
	this->current_block.getNewBlock();
	this->score = 0;
	this->line_clears = 0;
	int screen_height,screen_width;

	/* Intialise Screen */
	setlocale(LC_ALL, "");
	initscr();
	screen_height = LINES;
	screen_width = COLS;
	cbreak();																			/* Disable Line Buffering */
	noecho();																			/* Do not echo typed key */
	curs_set(0);																	/* Set Cursor Invisible */
	keypad(stdscr, TRUE);													/* For key values */
	/* TODO: check if a very small delay improves rendering performance */
	nodelay(stdscr, TRUE);												/* No wait on reading */
	refresh();																		/* To flush stdscr so that other windows are loaded above it */
	
	if (has_colors() == FALSE) {
		/* TODO: Change so that a black and white form of tetris can be played */
		endwin();
		printf("Your terminal does not support color\n");
		exit(EXIT_FAILURE);
	}
	this->formColours();
	
	this->game_board.createWindow(screen_height, screen_width);
	this->score_board.createWindow(screen_height, screen_width);
}

Tetris::~Tetris() {
	endwin();
}

/* Getters */
int Tetris::getNumberOfLineClears() {
	return this->line_clears;
}

int Tetris::getLevel() {
	return 1 + (line_clears / 10);
}

int Tetris::getScore() {
	return this->score;
}

/* Methods */
void Tetris::loop() {
	int pressed_key = ERR;
	this->game_over = false;

	this->score_board.render();

	while (!this->game_over) {
		clock_t t1 = clock(), t2 = clock();
		do {
			this->game_board.render();
			while (((pressed_key = getch()) == ERR) && ((t2 - t1) < CLOCKS_PER_SEC)) {
				t2 = clock();
			}
			if(pressed_key != ERR) {
				switch(pressed_key) {
					case KEY_DOWN:	this->current_block.moveOneStepDown();
													break;
					case KEY_LEFT:	this->current_block.moveOneStepLeft();
													break;
					case KEY_RIGHT: this->current_block.moveOneStepRight();
													break;
					case KEY_UP:		this->current_block.changeOrientation();
													break;
					default: break;
				}
			}
			t2 = clock();
		} while (t2 - t1 < CLOCKS_PER_SEC);
		
		if (this->current_block.isTouchingBelow()) {
			int linesCleared = this->game_board.lineClear();
			this->updateScore(linesCleared);

			try {
				this->current_block.getNewBlock();
			} catch (tetriminoOverlapException& toe) {
				this->game_over = true;
			}
		} else {
			this->current_block.moveOneStepDown();
		}
	}

	this->game_board.printGameOver();
	sleep(2);
}

void Tetris::updateScore(int linesCleared) {
	switch(linesCleared) {
		case 4:	this->score += 800 * this->getLevel();
						break;
		case 3:	this->score += 500 * this->getLevel();
						break;
		case 2:	this->score += 300 * this->getLevel();
						break;
		case 1:	this->score += 100 * this->getLevel();
						break;
	}

	this->line_clears += linesCleared;
	this->score_board.update(this->score);
}

void Tetris::formColours() {
	start_color();
	use_default_colors(); /* For -1 colour to be set */

	/*
	 * Color RGB values are scaled in the
	 * range 0 to 1000 in ncurses
	 */
	init_color(Cyan, 0, 624, 855);
	init_color(Blue, 0, 396, 741);
	init_color(Orange, 1000, 475, 0);
	init_color(Yellow, 996, 796, 0);
	init_color(Green, 412, 745, 157);
	init_color(Purple, 584, 176, 596);
	init_color(Red, 929, 161, 224);
	init_color(BG1, 176, 176, 176);
	init_color(BG2, 157, 157, 157);
	
	/* Initialising Colour Pairs */
	init_pair(BLOCK_NONE, -1, -1);
	init_pair(BLOCK_CYAN, -1, Cyan);
	init_pair(BLOCK_BLUE, -1, Blue);
	init_pair(BLOCK_ORANGE, -1, Orange);
	init_pair(BLOCK_YELLOW, -1, Yellow);
	init_pair(BLOCK_GREEN, -1, Green);
	init_pair(BLOCK_PURPLE, -1, Purple);
	init_pair(BLOCK_RED, -1, Red);
	init_pair(BLOCK_BG1, -1, BG1);
	init_pair(BLOCK_BG2, -1, BG2);
}

