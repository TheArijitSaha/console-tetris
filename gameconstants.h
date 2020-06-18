#ifndef GAMECONSTANTS_H_INCLUDED
#define GAMECONSTANTS_H_INCLUDED

//everything is static over here.

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

#define COLOR_RANGE 16
#define REDUCED_COLOR_RANGE 5

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

    const int BLOCK_COUNT = 7;//Exhaustive set of blocks in this game
    const int ORIENTATION_COUNT = 4;//All possible orientations of a single block
    const int BOARD_ROWS = 18;
    const int BOARD_COLUMNS = 13;
    const int EMPTY_INT = 0;//INTEGER value of EMPTY cell
    const int FILLED_INT = 1;//INTEGER value of FILLED cell
    const char EMPTY_CHAR = 176;//GRAPHICAL CHARACTER empty cell
    const char FILLED_CHAR = 219;//GRAPHICAL CHARACTER filled cell

    const int validColorList[] = {1,2,4,6,7};
    //BLOCKMATRIX CONTAINS THE ENTIRE MAP OF ALL COMBINATIONS OF ALL BLOCKS IN TETRIS
    const int blockMatrix[4*BLOCK_COUNT][4*ORIENTATION_COUNT] = {{1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,0},//0
                                {0,1,0,0,1,1,0,0,1,1,1,0,1,1,0,0},
                                {0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,1,0,1,1,0,0,1,0,0,0},//1
                                {0,1,0,0,0,0,1,0,1,0,0,0,1,1,1,0},
                                {1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0},//2
                                {0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0},
                                {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0},//3
                                {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0},//4
                                {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0},
                                {0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {1,0,0,0,0,0,1,0,1,1,0,0,1,1,1,0},//5
                                {1,0,0,0,1,1,1,0,0,1,0,0,1,0,0,0},
                                {1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1},//6
                                {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                                {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                                {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}};

#endif // GAMECONSTANTS_H_INCLUDED
