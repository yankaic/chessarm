#include "architecture.hpp"

int main(){
	Position from;
	from.column = 0;
	from.line = 1;

	Position to;
	to.column = 0;
	to.line = 2;

	Movement move;
	move.origin = from;
	move.destination = to;

	initBlackPieces();
	printBoard();
	recordMovement(move);
	cout << endl;
	printBoard();


	bool map[8][8] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 1, 0, 0, 0, 
		1, 1, 1, 1, 0, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	};
	recognize(map);
}