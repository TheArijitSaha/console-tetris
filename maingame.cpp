#include "maingame.h"
#include<conio.h>

MainGame::MainGame(HANDLE h)
{
    currentHandle = h;
}
void MainGame::gameInitialize()
{
    currentBlock.bindWithBoard(&mainBoard);
}

void MainGame::gameLoop()
{
    while(1)//block drop loop
    {
        t1=clock();//initialize reference time
        mainBoard.printBoard(currentHandle);
        do
        {
            while((!_kbhit()) && ((t2-t1)/CLOCKS_PER_SEC<1))
            {
                t2 = clock();
            }
            if(_kbhit())
            {
                pressed_key = _getch();
                mainBoard.eraseBoard();
                switch(pressed_key)
                {
                    case KEY_LEFT: currentBlock.moveOneStepLeft();
                    break;
                    case KEY_RIGHT: currentBlock.moveOneStepRight();
                    break;
                    case KEY_UP: currentBlock.changeCurrentOrientation();
                    break;
                }
                mainBoard.printBoard(currentHandle);
            }
            t2 = clock();
        }while((t2-t1)<700);
        if(currentBlock.isTouchingBelow())
        {
            currentBlock.sampleRandomBlock();
        }
        else
        {
            currentBlock.moveOneStepDown();
        }
        mainBoard.eraseBoard();
    }
}
