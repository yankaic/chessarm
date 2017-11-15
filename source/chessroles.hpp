typedef unsigned long Map;
#define BOARD_SIZE 8 

#include <cmath>

struct Square{
	int line;
	int column;
};

struct Vector{
	int x;
	int y;
};

Map 		map(int line, int column); //ok
Map 		map(Square square);   //ok
Square 	getLocation(Map map); //ok
char* 	toString(Map map, char* text, char ch);
char*		toString(Map map);   //ok
char* 	emptyString();
int 		count(Map map);   //ok

Map northAttacks		(Map occupied, Square square);
Map northeastAttacks(Map occupied, Square square);
Map eastAttacks			(Map occupied, Square square);
Map southeastAttacks(Map occupied, Square square); 
Map southAttacks		(Map occupied, Square square);
Map southwestAttacks(Map occupied, Square square);
Map westAttacks			(Map occupied, Square square);
Map northwestAttacks(Map occupied, Square square);
Map targetedAttacks	(Map occupied, Square square, Vector direction);

Map pawnAttacks			(Map occupied, Square square, bool isWhite);
Map rookAttacks    	(Map occupied, Square square);
Map bishopAttacks  	(Map occupied, Square square); 
Map knightAttacks		(Map occupied, Square square); 
Map queenAttacks   	(Map occupied, Square square);
Map kingAttacks   	(Map occupied, Square square);