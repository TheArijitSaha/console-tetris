#include<stdlib.h>
#include "maingame.h"
using namespace std;

int main()
{
    //get handle of current process.

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    MainGame game(h);
    game.gameInitialize();
    game.gameLoop();
    return 0;
}
