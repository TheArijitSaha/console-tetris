#include "maingame.h"
#include<iostream>
#include<conio.h>

MainGame::MainGame(HANDLE h)
{
    currentHandle = h;
}
void MainGame::gameInitialize()
{
    currentBlock.bindWithBoard(&mainBoard);
}
void MainGame::printGameOver()
{
    std::cout<<"GAME OVER\n";
}
void MainGame::slashRoutine()
{
    mainBoard.updateRoof();
    mainBoard.updateSlashIndices();
    mainBoard.slashRows();
}
void MainGame::gameLoop()
{
    gameOver = false;
    while(!gameOver)//block drop loop
    {
        t1=clock();//initialize reference time
        t2=clock();
        mainBoard.printBoard(currentHandle);
        do//runs for finite time interval within which user can change position/orientation of block
        {
            while((!_kbhit()) && ((t2-t1)<500))
            {
                t2 = clock();
            }
            if(_kbhit())
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
            }
            t2 = clock();
        }while((t2-t1)<500);
        if(currentBlock.isTouchingBelow())
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
        }
        mainBoard.eraseBoard();
    }
    printGameOver();
    _getch();
}
