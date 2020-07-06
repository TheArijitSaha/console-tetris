#include "tetris.h"
#include <iostream>
//#include <conio.h>

using namespace std;

/* TODO */
Tetris::Tetris(): board() {
}
/*
 * initialise()
 */
void Tetris::initialise() {
	system("clear");
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
	this->gameOver = false;
	while (!this->gameOver) {
		clock_t t1 = clock(), t2 = clock();
		do {
			this->board.render();
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
		this->board.erase();
	}
	// printGameOver();
}

