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

Movement recognize(bool map[BOARD_SIZE][BOARD_SIZE]){
	bool oldmap[BOARD_SIZE][BOARD_SIZE];
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			oldmap[line][column] = board[line][column] != EMPTY;
		}
	}

	printMap(oldmap);
	printMap(map);
}

void printMap(bool map[BOARD_SIZE][BOARD_SIZE]){
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			cout << map[line][column] << ' ';
		}
		cout << endl;
	}
	cout << endl;	
}