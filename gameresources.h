#ifndef GAMERESOURCES_H_INCLUDED
#define GAMERESOURCES_H_INCLUDED
#include<windows.h>
#include "gameconstants.h"

//Instantiable structs

class GameBoard
{
public:
    int BoardMatrix[BOARD_ROWS][BOARD_COLUMNS];//stores EMPTY_INT or FILLED_INT
    int BoardColorMatrix[BOARD_ROWS][BOARD_COLUMNS];//stores color of each cell of the board
    GameBoard();
    void printBoard(HANDLE h);
    void eraseBoard();
};

class TetBlock
{
    GameBoard *bindedBoard;//Points to the GameBoard object to which this TetBlock object is binded.
public:

    int blockShape[4][4];//stores the shape of block in 2D matrix form, represented by 0/1
    int maxX,maxY;//stores max range of the block in blockShape Matrix
    int posX,posY;//stores the position of the block w.r.t. gameBoard.
    int blockColor;
    int block_index;//block ID in blockmatrix
    int orientation_index;//orientation ID of that block in blockmatrix

    TetBlock(GameBoard *gb);//Constructor

    ///SAMPLING METHODS
    void sampleRandomBlock();//Samples a random block from block matrix, with random color, random orientation.
    void reSample();//Actual function that samples a block, given all other parameters of this TetBlock.
    void changeCurrentOrientation();//Rotate the current block assigned to this TetBlock

    ///SENSING METHODS
    bool isTouchingLaterally();//is this block touching board or other block vertically??
    bool isTouchingLeft();//left edge of this block touching anything?
    bool isTouchingRight();//right edge of this block touching anything?
    bool isTouchingBelow();//Base of this block touching anything?
    bool isOverlapping();//Block overlapping with existing blocks?

    ///STAMPING METHODS (TO STAMP/UN-STAMP THIS BLOCK ON THE GAMEBOARD)
    void stamp();
    void unstamp();

    ///MOVEMENT METHODS
    void moveOneStepDown();
    void moveOneStepLeft();
    void moveOneStepRight();

};

//void initializeBlockMatrix();
#endif // GAMERESOURCES_H_INCLUDED
