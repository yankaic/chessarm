#include "board.hpp"


void recordMovement(Movement move){
	board[move.destination.line][move.destination.column] = board[move.origin.line][move.origin.column];
	board[move.origin.line][move.origin.column] = EMPTY;

	bool fowardIsOne;
	bitset<64> foward, defender;

	if(getBit(playerOne, move.origin.line, move.origin.column)){		
		foward = playerOne;
		defender = playerTwo;
		fowardIsOne = true;
	}
	else{
		foward = playerTwo;
		defender = playerOne;
		fowardIsOne = false;
	}

	foward = clearBit(foward, move.origin.line, move.origin.column);		
	foward = setBit(foward, move.destination.line, move.destination.column);
	defender = clearBit(defender, move.destination.line, move.destination.column);	

	if(fowardIsOne){
		playerOne = foward;
		playerTwo = defender;
	}
	else{
		playerOne = defender;
		playerTwo = foward;
	}
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


Movement recognize(bitset<64> map){
	Position position = getOrigin(map);
	printMap(map);
	cout << "origin.line: " << position.line << endl;
	cout << "origin.column: " << position.column << endl;
}

Position getOrigin(bitset<64> map){
	bitset<64> oldmap;
	oldmap = getMap(board);
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
	else {
		return discoverMovement(getOrigin(map));
	}
}

Position discoverMovement(Position origin){
	bitset<64> moves = getPossibleMoves(origin);
	moves = getAvailableAttacks(origin, moves);
	if(count(moves)==1){
		return getMovement(moves);
	}
	Position location;
	location.line = -1;
	location.column = -1;
	return location;
}

bitset<64> getAvailableMoves(Position origin, bitset<64> possibleMoves){
	bitset<64> disjunction;
	disjunction = getBit(playerOne, origin.line, origin.column) ? playerOne : playerTwo;
	unsigned long possibleRepresentation = possibleMoves.to_ulong();
	unsigned long disjunctionRepresentation = disjunction.to_ulong();
	unsigned long availablesRepresentation = possibleRepresentation - disjunctionRepresentation;
	bitset<64> availables (availablesRepresentation);
	return availables;
}


bitset<64> getAvailableAttacks(Position origin, bitset<64> possibleMoves){	
	bitset<64> opponent;
	opponent = getBit(playerOne, origin.line, origin.column) ? playerTwo : playerOne;
	return possibleMoves & opponent;
}

bitset<64> getPossibleMoves(Position origin){
	unsigned char piece = board[origin.line][origin.column];
	bitset<64> moves;
	switch(piece){
		case PAWN:
			return getPawnMoves(origin, getBit(playerTwo, origin.line, origin.column));
		case ROOK:
			return getRookMoves(origin);
		case KNIGHT:
			return getKnightMoves(origin);
		case BISHOP:
			return getBishopMoves(origin);
		case QUEEN:
			return getQueenMoves(origin);
		case KING:
			return getKingMoves(origin);
		default:
			return moves;
	}
}
