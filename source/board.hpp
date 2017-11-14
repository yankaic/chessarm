
typedef unsigned long long Map;
#define BOARD_SIZE 8 
#define OCCUPIED_SQUARES ((whitePieces | blackPieces))

struct Square{
	int line;
	int column;
};

struct Vector{
	int x;
	int y;
};

struct Movement{
	Square origin;
	Square destination;
};

Map whitePieces 	= 0x000000000000FFFD;
Map blackPieces		= 0xFFFF000000000000;

Map pawnPieces 		= 0x00FF00000000FF00;
Map rookPieces 		= 0x8100000000000081;
Map knightPieces	= 0x4200000000000042;
Map bishopPieces 	= 0x2400000000000024;
Map queenPieces 	= 0x1000000000000010;
Map kingPieces 		= 0x0800000000000008;

Map 		map(int line, int column); 
Map 		map(Square square);  
Square 	getLocation(Map map);
char*		toString(Map map);  
int 		count(Map map);  

Map northAttacks		(Map occupied, Square square);
Map northeastAttacks(Map occupied, Square square);
Map eastAttacks			(Map occupied, Square square);
Map southeastAttacks(Map occupied, Square square); 
Map southAttacks		(Map occupied, Square square);
Map southwestAttacks(Map occupied, Square square);
Map westAttacks			(Map occupied, Square square);
Map northwestAttacks(Map occupied, Square square);
Map targetedAttacks	(Map occupied, Square square, Vector direction);

Map pawnAttacks			(Map occupied, Square square);
Map rookAttacks    	(Map occupied, Square square);
Map bishopAttacks  	(Map occupied, Square square); 
Map knightAttacks		(Map occupied, Square square); 
Map queenAttacks   	(Map occupied, Square square);
Map kingAttacks   	(Map occupied, Square square);


