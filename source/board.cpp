#include "board.hpp"

void recordMovement(Movement move){
	//precisa descobrir quem vai ceder lugar para o movimentador.
	Map origin = map(move.origin);
	Map destination = map(move.destination);

	if(contains(whitePieces, origin))
		whitePieces |= destination;

	if(contains(blackPieces, origin))
		blackPieces |= destination;

	if(contains(pawnPieces, origin))
		pawnPieces |= destination;

	if(contains(rookPieces, origin))
		rookPieces |= destination;

	if(contains(knightPieces, origin))
		knightPieces |= destination;

	if(contains(bishopPieces, origin))
		bishopPieces |= destination;

	if(contains(queenPieces, origin))
		queenPieces |= destination;

	whitePieces &= ~origin;
	blackPieces &= ~origin;

	pawnPieces &= ~origin;
	rookPieces &= ~origin;
	knightPieces &= ~origin;
	bishopPieces &= ~origin;
	queenPieces &= ~origin;
	kingPieces &= ~origin;
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
