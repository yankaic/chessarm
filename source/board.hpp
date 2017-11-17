#ifndef ROLESLIB
#define ROLESLIB
#include "chessroles.cpp"
#endif

// indices para o tabuleiro abaixo
#define WHITE 	0
#define BLACK 	1
#define PAWN 		2
#define ROOK 		3
#define KNIGHT 	4
#define BISHOP 	5
#define QUEEN 	6
#define KING 		7
#define occupiedSquares ((pieces[WHITE] | pieces[BLACK]))

Map pieces[8] = {
	0x000000000000FFFF,	//white
	0xFFFF000000000000,	//black
	0x00FF00000000FF00, //pawn
	0x8100000000000081,	//rook
	0x4200000000000042,	//knight
	0x2400000000000024,	//bishop
	0x0800000000000008,	//queen
	0x1000000000000010	//king
};

struct Movement{
	Square origin;
	Square destination;
};



Map* pointer = &pieces[2];

Map* whitePieces 		= &pieces[WHITE];
Map* blackPieces		= &pieces[BLACK];

Map* pawnPieces 		= &pieces[PAWN];
Map* rookPieces 		= &pieces[ROOK];
Map* knightPieces		= &pieces[KNIGHT];
Map* bishopPieces 	= &pieces[BISHOP];
Map* queenPieces 		= &pieces[QUEEN];
Map* kingPieces 		= &pieces[KING];

void recordMovement(Movement move); 

int pieceType(Square Square);
int pieceColor(Square);

char* boardString();
char* whiteString();
char* blackString();






