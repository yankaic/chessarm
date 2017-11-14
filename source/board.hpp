
typedef unsigned long long Map;
#define BOARD_SIZE 8 
#define OCCUPIED_SQUARES whitePieces | blackPieces

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

Map whitePieces = 0x0;
Map blackPieces = 0x0;

Map pawnPieces = 0x0;
Map rookPieces = 0x0;
Map bishopPieces = 0x0;
Map knightPieces = 0x0;
Map queenPieces = 0x0;
Map kingPieces = 0x0;

Map 		map(int line, int column); 
Map 		map(Square square);  
Square 	getLocation(Map map);
void 		print(Map map);  
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

