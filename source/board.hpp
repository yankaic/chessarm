#include <iostream>
#include "pieces.cpp"

using namespace std;

bool turn = false;



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





