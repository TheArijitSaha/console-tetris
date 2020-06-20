#ifndef MAINGAME_H_INCLUDED
#define MAINGAME_H_INCLUDED
#include "gameresources.h"
#include<time.h>

class MainGame
{
    GameBoard mainBoard;
    TetBlock currentBlock;
    clock_t t1,t2;
    HANDLE currentHandle;
    char pressed_key;

    bool gameOver;
    void slashRoutine();
    void printGameOver();

public:
    MainGame(HANDLE h);//Pss the handle of current process to the constructor
    void gameInitialize();//method to initialize object variables.
    void gameLoop();//method that runs forever.
};


#endif // MAINGAME_H_INCLUDED
