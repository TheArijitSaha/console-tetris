#ifndef CONSTANTS
#define CONSTANTS

/* Board Properties */
const int BOARD_ROWS = 20;
const int BOARD_COLUMNS = 10;

/* Cell */
enum Cell {
	Empty,
	Full
};

/* CellColour */
enum CellColour {
	None,
	Cyan,
	Blue,
	Orange,
	Yellow,
	Green,
	Purple,
	Red,
	BG1,
	BG2
};

/* Block Colour Pairs */
enum BlockColour {
	BLOCK_NONE,
	BLOCK_CYAN,
	BLOCK_BLUE,
	BLOCK_ORANGE,
	BLOCK_YELLOW,
	BLOCK_GREEN,
	BLOCK_PURPLE,
	BLOCK_RED,
	BLOCK_BG1,
	BLOCK_BG2
};

/* Point */
struct Point {
	int Y, X;
};

/* Block Patterns */
const int BLOCK_COUNT = 7;
const int ORIENTATION_COUNT = 4;
const Point block_pattern[BLOCK_COUNT][ORIENTATION_COUNT][4] = {
	/* I-block */
	{ { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } },
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } },
		{ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } },
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } } },
	/* J-block */
	{ { { 0, 1 }, { 1, 1 }, { 2, 0 }, { 2, 1 } },
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 } },
		{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 } },
		{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } } },
	/* L-block */
	{ { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 } },
		{ { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },
		{ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 } } },
	/* O-block */
	{ { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },
		{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },
		{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },
		{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } } },
	/* S-block */
	{ { { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 } },
		{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },
		{ { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 } },
		{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 } } },
	/* T-block */
	{ { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },
		{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } },
		{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },
		{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 1 } } },
	/* Z-block */
	{ { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },
		{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 0 } },
		{ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },
		{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 0 } } }
};

#endif /* CONSTANTS */

