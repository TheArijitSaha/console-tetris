#include <iostream>
#include "game_board.h"

using namespace std;

GameBoard::GameBoard() {
	this->board_win = nullptr;
	this->row_count = BOARD_ROWS;
	this->column_count = BOARD_COLUMNS;

	this->board_matrix = (Cell**) malloc(sizeof(Cell*) * this->row_count);
	this->board_colour_matrix = (BlockColour**) malloc(sizeof(BlockColour*) * this->row_count);
	for (int i = 0; i < this->row_count; ++i) {
		this->board_matrix[i] = (Cell*) malloc(sizeof(Cell) * this->column_count);
		this->board_colour_matrix[i] = (BlockColour*) malloc(sizeof(BlockColour) * this->column_count);
		for (int j = 0; j < this->column_count; ++j) {
			this->board_matrix[i][j] = Empty;
			this->board_colour_matrix[i][j] = BLOCK_NONE;
		}
	}
}

GameBoard::~GameBoard() {
	if (this->board_win != nullptr) {
		delwin(this->board_win);
	}
}

/* Getters */
Cell GameBoard::getCell(int X, int Y) {
	if ((X < 0) || (X >= this->column_count) || (Y < 0) || (Y >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid cell Coordinates (%d, %d)\n", X, Y);
		exit(EXIT_FAILURE);
	}

	return this->board_matrix[Y][X];
}

int GameBoard::getRowCount() {
	return this->row_count;
}

int GameBoard::getColumnCount() {
	return this->column_count;
}

/* Setters */
void GameBoard::setCell(int X, int Y, Cell val) {
	if ((X < 0) || (X >= this->column_count) || (Y < 0) || (Y >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid cell Coordinates (%d, %d)\n", X, Y);
		exit(EXIT_FAILURE);
	}

	this->board_matrix[Y][X] = val;
}

void GameBoard::setColour(int X, int Y, BlockColour val) {
	if ((X < 0) || (X >= this->column_count) || (Y < 0) || (Y >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid cell Coordinates (%d, %d)\n", X, Y);
		exit(EXIT_FAILURE);
	}

 this->board_colour_matrix[Y][X] = val;
}

/* Methods */
void GameBoard::render() {
	wclear(this->board_win);
	for (int i = 0; i < this->row_count; ++i) {
		wmove(this->board_win, i, 0);
		for (int j = 0; j < this->column_count; ++j) {
			if (this->board_matrix[i][j] == Empty) {
				if ((i + j) % 2 == 0) {
					wattron(this->board_win, COLOR_PAIR(BLOCK_BG1));
				} else {
					wattron(this->board_win, COLOR_PAIR(BLOCK_BG2));
				}
				wprintw(this->board_win, "  ");
				if ((i + j) % 2 == 0) {
					wattroff(this->board_win, COLOR_PAIR(BLOCK_BG1));
				} else {
					wattroff(this->board_win, COLOR_PAIR(BLOCK_BG2));
				}
			} else {
				wattron(this->board_win, COLOR_PAIR(this->board_colour_matrix[i][j]));
				wprintw(this->board_win, "  ");
				wattroff(this->board_win, COLOR_PAIR(this->board_colour_matrix[i][j]));
			}
		}
	}
	wrefresh(this->board_win);
}

void GameBoard::createGameBoardWindow() {
	if (this->board_win != nullptr) {	// Already initialised
		return;
	}
	int starty = (LINES - this->row_count) / 2;
	int startx = (COLS - this->column_count * 2) / 2;
	this->board_win = newwin(this->row_count, this->column_count * 2, starty, startx);
	wrefresh(this->board_win);
}

void GameBoard::lineClear() {
	int rows_cleared_below = 0;
	for (int row = this->row_count - 1; row >= 0; --row) {
		if (this->isFilledRow(row)) {
			this->clearRow(row);
			rows_cleared_below++;
		} else {
			this->copyRow(row, row + rows_cleared_below);
		}
	}
}

bool GameBoard::isFilledRow(int row_number) {
	if ((row_number < 0) || (row_number >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid row number -> %d\n", row_number);
		exit(EXIT_FAILURE);
	}

	for (int col = 0; col < this->column_count; ++col) {
		if (this->board_matrix[row_number][col] == Empty) return false;
	}

	return true;
}

void GameBoard::clearRow(int row_number) {
	if ((row_number < 0) || (row_number >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid row number -> %d\n", row_number);
		exit(EXIT_FAILURE);
	}

	for (int col = 0; col < this->column_count; ++col) {
		this->board_matrix[row_number][col] = Empty;
	}
}

void GameBoard::copyRow(int source_row, int target_row) {
	if ((source_row < 0) || (target_row < 0)
			|| (source_row >= this->row_count)
			|| (target_row >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid row copy pair: %d -> %d\n", source_row, target_row);
		exit(EXIT_FAILURE);
	}

	for (int col = 0; col < this->column_count; ++col) {
		this->board_matrix[target_row][col] = this->board_matrix[source_row][col];
		this->board_colour_matrix[target_row][col] = this->board_colour_matrix[source_row][col];
	}
}

bool GameBoard::isCellFull(int X, int Y) {
	if ((X < 0) || (X >= this->column_count) || (Y < 0) || (Y >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid cell Coordinates (%d, %d)\n", X, Y);
		exit(EXIT_FAILURE);
	}

	return (this->board_matrix[Y][X] == Full);
}

bool GameBoard::isCellEmpty(int X, int Y) {
	if ((X < 0) || (X >= this->column_count) || (Y < 0) || (Y >= this->row_count)) {
		endwin();
		fprintf(stderr, "PROGRAM ERROR: Invalid cell Coordinates (%d, %d)\n", X, Y);
		exit(EXIT_FAILURE);
	}

	return (this->board_matrix[Y][X] == Empty);
}

void GameBoard::printGameOver() {
	int message_height = 5;
	int message_width = 12;
	int message_X = (this->column_count * 2 - message_width)/ 2;
	int message_Y = (this->row_count - message_height)/ 2;

	wattron(this->board_win, A_STANDOUT);
	wattron(this->board_win, A_BOLD);
	wmove(this->board_win, message_Y, message_X);
	wprintw(this->board_win, "           ");
	wmove(this->board_win, message_Y + 1, message_X);
	wprintw(this->board_win, "  G A M E  ");
	wmove(this->board_win, message_Y + 2, message_X);
	wprintw(this->board_win, "           ");
	wmove(this->board_win, message_Y + 3, message_X);
	wprintw(this->board_win, "  O V E R  ");
	wmove(this->board_win, message_Y + 4, message_X);
	wprintw(this->board_win, "           ");
	wattroff(this->board_win, A_BOLD);
	wattroff(this->board_win, A_STANDOUT);
	wrefresh(this->board_win);
}

