#include "gameresources.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

///GAMEBOARD
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
    system("cls");
}

///TETBLOCK
TetBlock::TetBlock()
{

}
TetBlock::TetBlock(GameBoard *gb)
{
    bindedBoard = gb;
    sampleRandomBlock();
}
void TetBlock::bindWithBoard(GameBoard *gb)
{
    bindedBoard = gb;
    sampleRandomBlock();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TetBlock::stamp()
{
    int i,j;
    for(i=0;i<=maxX;++i)
    {
        for(j=0;j<=maxY;++j)
        {
            if(blockShape[i][j] == FILLED_INT)
            {
                bindedBoard->BoardMatrix[posX+i][posY+j] = FILLED_INT;
                bindedBoard->BoardColorMatrix[posX+i][posY+j] = blockColor;
            }
        }
    }
}

void TetBlock::unstamp()
{
    int i,j;
    for(i=0;i<=maxX;++i)
    {
        for(j=0;j<=maxY;++j)
        {
            if(blockShape[i][j] == FILLED_INT)
            {
                bindedBoard->BoardMatrix[posX+i][posY+j] = EMPTY_INT;
                bindedBoard->BoardColorMatrix[posX+i][posY+j] = WHITE;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool TetBlock::isTouchingLaterally()
{
    if(posY == 0 || (posY + maxY == BOARD_COLUMNS-1)) return true;//Reached the vertical edge of board

    int i;
    for(i=0;i<=maxX;++i)
    {
        if(((bindedBoard->BoardMatrix[posX+i][posY-1] == FILLED_INT)&&(blockShape[i][0] == FILLED_INT)) || ((bindedBoard->BoardMatrix[posX+i][posY+maxY+1] == FILLED_INT) && (blockShape[i][maxY] == FILLED_INT))) return true;
    }
    return false;
}

bool TetBlock::isTouchingLeft()
{
    if(posY == 0) return true;//Reached the left vertical edge of board

    int i;
    for(i=0;i<=maxX;++i)
    {
        if((bindedBoard->BoardMatrix[posX+i][posY-1] == FILLED_INT)&&(blockShape[i][0] == FILLED_INT)) return true;
    }
    return false;
}

bool TetBlock::isTouchingRight()
{
    if(posY + maxY == BOARD_COLUMNS-1) return true;//Reached the vertical edge of board

    int i;
    for(i=0;i<=maxX;++i)
    {
        if((bindedBoard->BoardMatrix[posX+i][posY+maxY+1] == FILLED_INT) && (blockShape[i][maxY] == FILLED_INT)) return true;
    }
    return false;
}


bool TetBlock::isTouchingBelow()
{
    if(posX+maxX==BOARD_ROWS-1) return true;//Reached the floor of the board
    int j;
    for(j=0;j<=maxY;++j)
    {
        if((bindedBoard->BoardMatrix[posX+maxX+1][posY+j] == FILLED_INT) && (blockShape[maxX][j] == FILLED_INT)) return true;
    }
    return false;
}

bool TetBlock::isOverlapping()
{
    int i,j;
    for(i=0;i<=maxX;++i)
    {
        for(j=0;j<=maxY;++j)
        {
            if((bindedBoard->BoardMatrix[posX+i][posY+j] == FILLED_INT)&& (blockShape[i][j] == FILLED_INT)) return true;
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TetBlock::reSample()
{
    maxX=maxY=0;
    int i,j;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        {
            blockShape[i][j] = blockMatrix[4*block_index+i][4*orientation_index + j];
            if(blockShape[i][j] == FILLED_INT)
            {
                if(i>maxX) maxX = i;
                if(j>maxY) maxY = j;
            }
        }
    }
}
void TetBlock::sampleRandomBlock()
{
    posX = 0;
    srand (time(NULL));

    block_index = rand()%BLOCK_COUNT;
    orientation_index = rand()%ORIENTATION_COUNT;

    blockColor = validColorList[rand()%REDUCED_COLOR_RANGE];

    reSample();
    posY = rand()%(BOARD_COLUMNS-maxY);
    stamp();
}

void TetBlock::changeCurrentOrientation()
{
    int overlapX;
    int overlapY;
    int i,j;
    int oldPosX, oldPosY;
    int cnt = 0;
    unstamp();
    do
    {
        //store current position of the block
        oldPosX = posX;
        oldPosY = posY;
        //rotate the block
        orientation_index = (orientation_index+1)%ORIENTATION_COUNT;
        reSample();
        //reposition if overlapping
        overlapX = maxX+1;
        overlapY = maxY+1;

        for(i=0;i<=maxX;++i)
        {
            for(j=0;j<=maxY;++j)
            {
                if((bindedBoard->BoardMatrix[posX+i][posY+j] == FILLED_INT)&& (blockShape[i][j] == FILLED_INT))
                {
                    if(i<overlapX) overlapX = i;
                    if(j<overlapY) overlapY = j;
                }
            }
        }

        posX = posX-maxX-1+overlapX;
        posY = posY-maxY-1+overlapY;

        if(isOverlapping())//if still overlapping, revert back to the original position and try another orientation in the next loop run
        {
            posX=oldPosX;
            posY=oldPosY;
        }
        else//else stop rotating and exit this function
        {
            stamp();
            break;
        }
        ++cnt;
    }while (cnt!=4);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TetBlock::moveOneStepLeft()
{
    if(!isTouchingLeft())
    {
        unstamp();
        --posY;
        stamp();
    }
}
void TetBlock::moveOneStepRight()
{
    if(!isTouchingRight())
    {
        unstamp();
        ++posY;
        stamp();
    }
}
void TetBlock::moveOneStepDown()
{
    if(!isTouchingBelow())
    {
        unstamp();
        ++posX;
        stamp();
    }
}
