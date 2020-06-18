#include <iostream>
#include<stdlib.h>
#include "maingame.h"
using namespace std;

int main()
{
    //get handle of current process.

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    int i,j;
    /*for(i=0;i<4*BLOCK_COUNT;++i)
    {
        for(j=0;j<4*ORIENTATION_COUNT;++j)
        {
            if(blockMatrix[i][j] == EMPTY_INT)
            {
                SetConsoleTextAttribute(h,WHITE);
                cout<<EMPTY_CHAR;
            }
            else
            {
                SetConsoleTextAttribute(h,RED);
                cout<<FILLED_CHAR;
            }

        }
        cout<<'\n';
    }*/

    //GameBoard gb;
    /*for(i=0;i<min(BOARD_COLUMNS,BOARD_ROWS);++i)
    {
        gb.BoardMatrix[i][i] = FILLED_INT;
    }*/
   // TetBlock tb(&gb);
    //gb.printBoard(h);
    MainGame game(h);
    game.gameInitialize();
    game.gameLoop();
    return 0;
}
