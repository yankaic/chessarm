#ifndef ROLESLIB
#define ROLESLIB
#include "chessroles.cpp"
#endif


#define occupiedSquares ((whitePieces | blackPieces))

struct Movement{
	Square origin;
	Square destination;
};

Map whitePieces 	= 0x000000000000FFFF;
Map blackPieces		= 0xFFFF000000000000;

Map pawnPieces 		= 0x00FF00000000FF00;
Map rookPieces 		= 0x8100000000000081;
Map knightPieces	= 0x4200000000000042;
Map bishopPieces 	= 0x2400000000000024;
Map kingPieces 		= 0x1000000000000010;
Map queenPieces 	= 0x0800000000000008;






