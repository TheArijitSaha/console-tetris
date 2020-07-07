#include "tetris.h"
#include <iostream>
#include <ctime>
//#include <conio.h>

using namespace std;

Tetris::Tetris(): board(), current_block(&(this->board)) {
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
			this->current_block.getNewBlock();
			this->current_block.stamp();
			this->board.render();
			this->current_block.unstamp();
			while(/* TODO (!_kbhit())  && */((t2 - t1)<CLOCKS_PER_SEC)) {
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
		/*if(currentBlock.isTouchingBelow())
		{
				currentBlock.sampleRandomBlock();
				slashRoutine();
				//if(currentBlock.isOverlapping()) gameOver = true;
				if(mainBoard.roof <0) gameOver = true;
				else currentBlock.stamp();
		}
		else
		{
				currentBlock.moveOneStepDown();
		}*/
	}
	// printGameOver();
}

