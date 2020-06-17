#ifndef GAMERESOURCES_H_INCLUDED
#define GAMERESOURCES_H_INCLUDED
#include<windows.h>
#include "gameconstants.h"

//Instantiable structs
struct TetBlock
{
    int blockShape[4][4];//stores the shape of block in 2D matrix form, represented by 0/1
    int maxX,maxY;//stores max range of the block in blockShape Matrix
    int posX,posY;//stores the position of the block w.r.t. gameBoard.
    int blockColor;
};

class GameBoard
{
public:
    int BoardMatrix[BOARD_ROWS][BOARD_COLUMNS];//stores EMPTY_INT or FILLED_INT
    int BoardColorMatrix[BOARD_ROWS][BOARD_COLUMNS];//stores color of each cell of the board
    GameBoard();
    void printBoard(HANDLE h);
    void eraseBoard();
};

//void initializeBlockMatrix();
#endif // GAMERESOURCES_H_INCLUDED
