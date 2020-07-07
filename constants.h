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
	CELL_COLOUR_COUNT
};

/* Colours */
const char* const COLOUR_BG[] = { "\e[48;2;45;45;45m", "\e[48;2;40;40;40m" };
const char COLOUR_RESET[] = "\033[0m";
const char* const COLOUR_CELL[] = {
	"" /* None */,
	"\e[48;2;0;159;218m" /* Cyan -- I */,
	"\e[48;2;0;101;189m" /* Blue -- J */,
	"\e[48;2;255;121;0m" /* Orange -- L */,
	"\e[48;2;254;203;0m" /* Yellow -- O */,
	"\e[48;2;105;190;40m" /* Green -- S */,
	"\e[48;2;149;45;152m" /* Purple -- T */,
	"\e[48;2;237;41;57m" /* Red -- Z */
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

/*
#define COLOR_RANGE 16
#define REDUCED_COLOR_RANGE 5

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

    const int validColorList[] = {1,2,4,6,7};
*/
#endif /* CONSTANTS */
