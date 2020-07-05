#include "tetris.h"
#include <iostream>

using namespace std;

int main() {
	Tetris game;
	game.initialise();
	game.loop();
	return 0;
}
