#include "board.hpp"

void recordMovement(Movement move){
	//precisa descobrir quem vai ceder lugar para o movimentador.
	Map origin = map(move.origin);
	Map destination = map(move.destination);

	if(contains(pieces[WHITE], origin))
		pieces[WHITE] |= destination;

	if(contains(pieces[BLACK], origin))
		pieces[BLACK] |= destination;

	if(contains(pieces[PAWN], origin))
		pieces[PAWN] |= destination;

	if(contains(pieces[ROOK], origin))
		pieces[ROOK] |= destination;

	if(contains(pieces[KNIGHT], origin))
		pieces[KNIGHT] |= destination;

	if(contains(pieces[BISHOP], origin))
		pieces[BISHOP] |= destination;

	if(contains(pieces[QUEEN], origin))
		pieces[QUEEN] |= destination;

	pieces[WHITE] &= ~origin;
	pieces[BLACK] &= ~origin;

	pieces[PAWN] &= ~origin;
	pieces[ROOK] &= ~origin;
	pieces[KNIGHT] &= ~origin;
	pieces[BISHOP] &= ~origin;
	pieces[QUEEN] &= ~origin;
	pieces[KING] &= ~origin;
}

char* boardString(){	
	char* text = emptyString();
	toString	(pieces[PAWN] 	& pieces[WHITE],	text,'p');
	toString	(pieces[ROOK] 	& pieces[WHITE],	text,'r');
	toString	(pieces[KNIGHT] & pieces[WHITE],	text,'h');
	toString	(pieces[BISHOP] & pieces[WHITE],	text,'b');
	toString	(pieces[QUEEN] 	& pieces[WHITE],	text,'q');
	toString	(pieces[KING] 	& pieces[WHITE],	text,'k');

	toString	(pieces[PAWN] 	& pieces[BLACK],	text,'P');
	toString	(pieces[ROOK] 	& pieces[BLACK],	text,'R');
	toString	(pieces[KNIGHT] & pieces[BLACK],	text,'H');
	toString	(pieces[BISHOP] & pieces[BLACK],	text,'B');
	toString	(pieces[QUEEN] 	& pieces[BLACK],	text,'Q');
	toString	(pieces[KING] 	& pieces[BLACK],	text,'K');
	return text;	
}

char* whiteString(){
	char* text = emptyString();
	toString	(pieces[PAWN] 	& pieces[WHITE],	text,'p');
	toString	(pieces[ROOK] 	& pieces[WHITE],	text,'r');
	toString	(pieces[KNIGHT] & pieces[WHITE],	text,'h');
	toString	(pieces[BISHOP] & pieces[WHITE],	text,'b');
	toString	(pieces[QUEEN] 	& pieces[WHITE],	text,'q');
	toString	(pieces[KING] 	& pieces[WHITE],	text,'k');
	return text;
}

char* blackString(){
	char* text = emptyString();
	toString	(pieces[PAWN] 	& pieces[BLACK],	text,'P');
	toString	(pieces[ROOK] 	& pieces[BLACK],	text,'R');
	toString	(pieces[KNIGHT] & pieces[BLACK],	text,'H');
	toString	(pieces[BISHOP] & pieces[BLACK],	text,'B');
	toString	(pieces[QUEEN] 	& pieces[BLACK],	text,'Q');
	toString	(pieces[KING] 	& pieces[BLACK],	text,'K');
	return text;	
}
