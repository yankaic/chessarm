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
	Position position = getOrigin(map);
	printMap(map);
	cout << "origin.line: " << position.line << endl;
	cout << "origin.column: " << position.column << endl;
}

Position getOrigin(bitset<64> map){
	bitset<64> oldmap;
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			oldmap = setBit(oldmap, board[line][column] != EMPTY, line, column);
		}
	}
	bitset<64> modifications= map ^ oldmap;  //xor
	bitset<64> origin = modifications & oldmap;
	cout << "quantidade: " << count(origin) << endl;
	return getMovement(origin);
}

Position getMovement(bitset<64> map){
	Position position;
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			if(getBit(map, line, column)){
				position.line = line;
				position.column = column;
				return position;
			}
		}
	}
	position.line = -1;
	position.column = -1;
	return position;
}


Position getDestination(bitset<64> map){
	bitset<64> oldmap;
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			oldmap = setBit(oldmap, board[line][column] != EMPTY, line, column);
		}
	}
	bitset<64> modifications = map ^ oldmap;  //xor
	bitset<64> destination = map & modifications;

	int resultCount = count(destination);
	if(resultCount == 1){
		return getMovement(destination);
	}
	else if(resultCount == 0){

	}
	else{

	}
}

Position discoverMovement(Position origin){

}

bitset<64> getPossibleMoves(Position origin){

}

bitset<64> getAvailableMoves(Position origin, bitset<64> possibleMoves){
	unsigned char piece = board[origin.line][origin.column];
	
}
