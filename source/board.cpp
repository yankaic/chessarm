#include "board.hpp"


void recordMovement(Movement move){
	board[move.destination.line][move.destination.column] = board[move.origin.line][move.origin.column];
	board[move.origin.line][move.origin.column] = EMPTY;
	turn = !turn;
}

void printBoard(){
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			if(board[line][column] == EMPTY){
				cout << '.';
			} else{
				cout << board[line][column];
			}
			cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void initBlackPieces(){
	for(int line = 0; line < BOARD_SIZE / 4; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			board[line][column] = toBlack(board[line][column]);
		}
	}
}

unsigned char toBlack(unsigned char piece){
	return piece - 32;
}

Movement recognize(bitset<64> map){
	bitset<64> oldmap;
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			oldmap = setBit(oldmap, board[line][column] != EMPTY, line, column);
		}
	}
	cout << "oldmap" << endl;
	printMap(oldmap);

	cout << "map" << endl;
	printMap(map);

	bitset<64> modifications= map ^ oldmap;  //xor
	bitset<64> origin = modifications & oldmap;

	cout << "modifications" << endl;
	printMap(modifications);

	cout << "origin" << endl;
	printMap(origin);

}

