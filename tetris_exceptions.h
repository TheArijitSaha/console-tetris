#ifndef TETRIS_EXCEPTIONS
#define TETRIS_EXCEPTIONS
#include <exception>

using namespace std;

class tetriminoOverlapException: public exception {
	public:
		const char* what() const throw() {
			return "Tetrimino Overlap Exception";
		}
};

#endif /* TETRIS_EXCEPTIONS */

