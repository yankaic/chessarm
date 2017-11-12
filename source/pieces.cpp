#include "pieces.hpp"

bitset<64> getPawnMoves(Position location, bool isOpositive){
	bitset<64> moves;
	int lineIncrease = 1;
	if(isOpositive)
		lineIncrease = -1;	

	moves = setBit(moves, location.line + lineIncrease, location.column + 1);
	moves = setBit(moves, location.line + lineIncrease, location.column - 1);
	return moves;
}

bitset<64> getRookMoves(Position location){	
	bitset<64> moves;
	for(int i = 0; i < BOARD_SIZE; i++){
		moves = setBit(moves, location.line, i);
		moves = setBit(moves, i, location.column);
	}
	moves = clearBit(moves, location.line, location.column);
	return moves;
}

bitset<64> getKnightMoves(Position location){	
	bitset<64> moves;
	for(int line = -2; line <= 2; line += 1){
		for(int column = -2; column <= 2; column += 1){
			if(abs(line)==abs(column) || line == 0 || column == 0)
				continue;
			moves = setBit(moves, location.line + line, location.column + column);
		}
	}
	return moves;
}

bitset<64> getBishopMoves(Position location){
	bitset<64> moves;

	//DIAGONAL PRINCIPAL
	int increase = -1 * min(location.line, location.column);
	
	while(abs(increase) < BOARD_SIZE){
		moves =  setBit(moves, increase + location.line, increase + location.column);
		increase++;
	}

	//DIAGONAL SECUNDARIA
	increase = max(location.line, location.column);
	

	while(abs(increase)<BOARD_SIZE){		
		moves = setBit(moves, increase + location.line, increase * (-1) + location.column);
		increase--;
	}
	moves = clearBit(moves, location.line, location.column);
	return moves;
}

bitset<64> getQueenMoves(Position location){
	return getBishopMoves(location) | getRookMoves(location);	
}

bitset<64> getKingMoves(Position location){	
	bitset<64> moves;
	for(int line = -1; line <= 1; line ++){
		for(int column = -1; column <= 1; column++){
			moves = setBit(moves, location.line + line, location.column + column);
		}
	}
	moves = clearBit(moves, location.line, location.column);
	return moves;
}

