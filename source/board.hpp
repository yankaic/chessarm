#include <iostream>
#include "bitmap.cpp"

using namespace std;

/*****************************************************************
*	DEFINICAO DAS PECAS	
* Pecas brancas sao definidas por letras minusculas e 
*	pecas pretas sao definidas por letras maiusculas.
* ****************************************************************/
const unsigned char PAWN 		=	'p';
const unsigned char ROOK 		= 'r';
const unsigned char KNIGHT 	= 'h';
const unsigned char BISHOP 	= 'b';
const unsigned char QUEEN 	= 'q';
const unsigned char KING 		= 'k';
const unsigned char EMPTY 	=  0;

bool turn = false;

struct Position{
	int line;
	int column;
};

struct Movement{
	Position origin;
	Position destination;
};


unsigned char board[BOARD_SIZE][BOARD_SIZE] = {
	ROOK,		KNIGHT,	BISHOP,	QUEEN,	KING,		BISHOP,	KNIGHT,	ROOK,
	PAWN,		PAWN,		PAWN,		PAWN,		PAWN,		PAWN,		PAWN,		PAWN,
	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,
	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,
	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,
	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,
	PAWN,		PAWN,		PAWN,		PAWN,		PAWN,		PAWN,		PAWN,		PAWN,
	ROOK,		KNIGHT,	BISHOP,	QUEEN,	KING,		BISHOP,	KNIGHT,	ROOK	
};

void initBlackPieces();

unsigned char toBlack(unsigned char piece);

void recordMovement(Movement move);

Movement recognize(bitset<64> map);

Position getOrigin(bitset<64> map);
Position getMovement(bitset<64> map);

Position getDestination(bitset<64> map);

Position discoverMovement(Position origin);

bitset<64> getPossibleMoves(Position origin);

bitset<64> getAvailableMoves(Position origin, bitset<64> possibleMoves);



