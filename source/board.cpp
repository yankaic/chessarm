#include "board.hpp"

void recordMovement(Movement move){

}

char* boardString(){	
	char* text = emptyString();
	toString	(pawnPieces 	& whitePieces,	text,'p');
	toString	(rookPieces 	& whitePieces,	text,'r');
	toString	(knightPieces & whitePieces,	text,'h');
	toString	(bishopPieces & whitePieces,	text,'b');
	toString	(queenPieces 	& whitePieces,	text,'q');
	toString	(kingPieces 	& whitePieces,	text,'k');

	toString	(pawnPieces 	& blackPieces,	text,'P');
	toString	(rookPieces 	& blackPieces,	text,'R');
	toString	(knightPieces & blackPieces,	text,'H');
	toString	(bishopPieces & blackPieces,	text,'B');
	toString	(queenPieces 	& blackPieces,	text,'Q');
	toString	(kingPieces 	& blackPieces,	text,'K');
	return text;	
}

char* whiteString(){
	char* text = emptyString();
	toString	(pawnPieces 	& whitePieces,	text,'p');
	toString	(rookPieces 	& whitePieces,	text,'r');
	toString	(knightPieces & whitePieces,	text,'h');
	toString	(bishopPieces & whitePieces,	text,'b');
	toString	(queenPieces 	& whitePieces,	text,'q');
	toString	(kingPieces 	& whitePieces,	text,'k');
	return text;
}

char* blackString(){
	char* text = emptyString();
	toString	(pawnPieces 	& blackPieces,	text,'P');
	toString	(rookPieces 	& blackPieces,	text,'R');
	toString	(knightPieces & blackPieces,	text,'H');
	toString	(bishopPieces & blackPieces,	text,'B');
	toString	(queenPieces 	& blackPieces,	text,'Q');
	toString	(kingPieces 	& blackPieces,	text,'K');
	return text;	
}
