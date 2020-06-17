#include "gameresources.h"
#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

//Constructor of GameBoard
GameBoard::GameBoard()
{
    int i,j;
    //initialize game board with all cells as EMPTY_INT (0)
    for(i=0;i<BOARD_ROWS;++i)
    {
        for(j=0;j<BOARD_COLUMNS;++j)
        {
            BoardMatrix[i][j] = EMPTY_INT;
            BoardColorMatrix[i][j] = WHITE;
        }
    }

}

void GameBoard::printBoard(HANDLE h)
{
    int i,j;
    for(i=0;i<BOARD_ROWS;++i)
    {
        for(j=0;j<BOARD_COLUMNS;++j)
        {
            if(BoardMatrix[i][j] == EMPTY_INT) cout<<EMPTY_CHAR;
            else
            {
                SetConsoleTextAttribute(h,BoardColorMatrix[i][j]);//SET TEXT COLOR TO COLOR OF CURRENT CELL
                cout<<FILLED_CHAR;
                SetConsoleTextAttribute(h,WHITE);//RESET TEXT COLOR TO WHITE
            }
        }
        cout<<'\n';
    }
}

void GameBoard::eraseBoard()
{
    system("clear");
}
