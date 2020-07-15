#include "tetris.h"
#include <ncurses.h>
#include <ctime>

using namespace std;

Tetris::Tetris(): board(), current_block(&(this->board)) {
	this->current_block.getNewBlock();

	/* Intialise Screen */
	initscr();
	cbreak();
	noecho();
	// keypad(stdscr, true/*TRUE*/);
	this->board.board_win = stdscr;
}

Tetris::~Tetris() {
	endwin();
}

/*void Tetris::printGameOver()
{
    std::cout<<"GAME OVER\n";
}
void Tetris::slashRoutine()
{
    mainBoard.updateRoof();
    mainBoard.updateSlashIndices();
    mainBoard.slashRows();
}*/
void Tetris::loop() {
	this->game_over = false;
	while (!this->game_over) {
		clock_t t1 = clock(), t2 = clock();
		do {
			this->board.render();
			while (/*(!(c = getchar() == '0')) && */((t2 - t1) < CLOCKS_PER_SEC)) {
				t2 = clock();
			}
			/*if(_kbhit())
			{
					pressed_key = _getch();
					switch(pressed_key)
					{
							case KEY_LEFT:  mainBoard.eraseBoard();
															currentBlock.moveOneStepLeft();
															mainBoard.printBoard(currentHandle);
							break;
							case KEY_RIGHT: mainBoard.eraseBoard();
															currentBlock.moveOneStepRight();
															mainBoard.printBoard(currentHandle);
							break;
							case KEY_UP:    mainBoard.eraseBoard();
															currentBlock.changeCurrentOrientation();
															mainBoard.printBoard(currentHandle);
							break;
							default: break;
					}
			}*/
			t2 = clock();
		} while (t2 - t1 < CLOCKS_PER_SEC);
		
		if (this->current_block.isTouchingBelow()) {
			//slashRoutine();
			//if(currentBlock.isOverlapping()) gameOver = true;
			//if(mainBoard.roof <0) gameOver = true;
				//else currentBlock.stamp();
			this->current_block.getNewBlock();
		} else {
			this->current_block.moveOneStepDown();
		}
	}
	// printGameOver();
}

