#include "chessroles.hpp"

char* toString(Map map){
	int i = 63;
	char* text = new char[65];
	text[64] = '\0';
	Map mostSig = 0x8000000000000000;

	for(int i = 0; i < 64; i++){
		text[i] = (map & mostSig) !=0 ? '1' : '0';
		map = map << 1;
	}
	return text;
}

Map map(int line, int column){
	Square square;
	square.line = line;
	square.column = column;
	return map(square);
}

Map map(Square square){
	if(square.line >= BOARD_SIZE || square.column >= BOARD_SIZE || square.line < 0 || square.column < 0)
		return 0;
	int shift = square.line * BOARD_SIZE + square.column;
	Map bit = 0x1;
	return bit << shift;
} 

Square getLocation(Map map){
	int count = -1;
	while(map != 0){
		count++;
		map = map >> 1;
	}
	Square square;
	square.line = count / BOARD_SIZE;
	square.column = count % BOARD_SIZE;
	return square;
}

int count(Map map){
	int count = 0;
	Map bit = 0x1;
	while(map != 0){
		if(map & bit == bit)
			count++;
		map =  map >> 1;
	}
	return count;
}


Map northAttacks(Map occupied, Square square){	
	Vector vector;
	vector.x = 0;
	vector.y = 1;
	return targetedAttacks(occupied, square, vector);
}

Map northeastAttacks(Map occupied, Square square){
	Vector vector;
	vector.x = 1;
	vector.y = 1;
	return targetedAttacks(occupied, square, vector);
}

Map eastAttacks(Map occupied, Square square){
	Vector vector;
	vector.x = 1;
	vector.y = 0;
	return targetedAttacks(occupied, square, vector);
}
Map southeastAttacks(Map occupied, Square square){
	Vector vector;
	vector.x = 1;
	vector.y = -1;
	return targetedAttacks(occupied, square, vector);
}
Map southAttacks(Map occupied, Square square){
	Vector vector;
	vector.x = 0;
	vector.y = -1;
	return targetedAttacks(occupied, square, vector);
}
Map southwestAttacks(Map occupied, Square square){	
	Vector vector;
	vector.x = -1;
	vector.y = -1;
	return targetedAttacks(occupied, square, vector);
}
Map westAttacks(Map occupied, Square square){
	Vector vector;
	vector.x = -1;
	vector.y = 0;
	return targetedAttacks(occupied, square, vector);
}
Map northwestAttacks(Map occupied, Square square){
	Vector vector;
	vector.x = -1;
	vector.y = 1;
	return targetedAttacks(occupied, square, vector);
}

Map targetedAttacks	(Map occupied, Square square, Vector vector){
	int scale = 1;
	Map nextAttack, attacks = 0;

	do{
		nextAttack = map(square.line + vector.y * scale, square.column + vector.x * scale);
		attacks |= nextAttack;
		scale++;
	}while((nextAttack & occupied) != nextAttack); //ate encontrar um obstaculo ou sair do tabuleiro

	return attacks;	
}

Map pawnAttacks	(Map occupied, Square square, bool isWhite){
	int yGap = isWhite ? 1 : -1;
	Map attacks = map(square.line + yGap, square.column -1);
	attacks |= map(square.line + yGap, square.column +1);
	return attacks;
}

Map rookAttacks(Map occupied, Square square){
	Map attacks = northAttacks(occupied, square);
	attacks |= eastAttacks(occupied, square);
	attacks |= southAttacks(occupied, square);
	attacks |= westAttacks(occupied, square);
	return attacks;
}

Map bishopAttacks(Map occupied, Square square){
	Map attacks = northeastAttacks(occupied, square);
	attacks |= southeastAttacks(occupied, square);
	attacks |= southwestAttacks(occupied, square);
	attacks |= northwestAttacks(occupied, square);
	return attacks;
}

Map knightAttacks(Map occupied, Square square){
	Vector vect;
	Map attacks = 0, nextAttack;
	for(vect.x = -2; vect.x <= 2; vect.x++){
		for(vect.y = -2; vect.y <= 2; vect.y++){
			if(std::abs(vect.x) + std::abs(vect.y) == 3){
				nextAttack = map(square.line + vect.y, square.column + vect.x);
				attacks |= nextAttack;
			}
		}
	}
	return attacks;
}
Map queenAttacks(Map occupied, Square square){
	Map attacks = rookAttacks(occupied, square);
	attacks |= bishopAttacks(occupied, square);
	return attacks;
}

Map kingAttacks(Map occupied, Square square){
	Vector vect;
	Map attacks = 0, nextAttack;
	for(vect.x = -1; vect.x < 2; vect.x++){
		for(vect.y = -1; vect.y < 2; vect.y++){
			nextAttack = map(square.line + vect.y, square.column + vect.x);
			attacks |= nextAttack;
		}
	}
	 Map itself = map(square);
	 attacks -= itself;
	return attacks;
}