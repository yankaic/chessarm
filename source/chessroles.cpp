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
	while(true){
		nextAttack = map(square.line + vector.y * scale, square.column + vector.x * scale);
		attacks = attacks | nextAttack;
		if((nextAttack & occupied) == nextAttack)
			return attacks;	
		scale++;
	}
	return attacks;
}