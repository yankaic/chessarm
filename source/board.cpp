#include "board.hpp"

void recordMovement(Movement move){
	//precisa descobrir quem vai ceder lugar para o movimentador.
	Map origin = map(move.origin);
	Map destination = map(move.destination);

	int piece, color;
	for(piece = PAWN; piece <= KING && !contains(pieces[piece], origin); piece++){}
	color = contains(pieces[WHITE], origin) ? WHITE : BLACK;

	pieces[piece] |= destination;
	pieces[color] |= destination;

	int offensive = piece;
	for(piece = WHITE; piece <= KING; piece++){		
 		if(!(piece == offensive || piece == color))
			pieces[piece] &= ~destination;
		pieces[piece] &= ~origin;		
	}
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
