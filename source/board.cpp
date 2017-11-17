#include "board.hpp"

void recordMovement(Movement move){
	Map origin = map(move.origin);
	Map destination = map(move.destination);

	int offensive = pieceType(move.origin);
	int color = pieceColor(move.origin);

	pieces[offensive] |= destination;
	pieces[color] |= destination;

	for(int piece = WHITE; piece <= KING; piece++){		
 		if(!(piece == offensive || piece == color))
			pieces[piece] &= ~destination;
		pieces[piece] &= ~origin;		
	}
}

int pieceType(Square square){
	int piece;
	for(piece = PAWN; piece <= KING && !contains(pieces[piece], map(square)); piece++){}
	return piece;
}

int pieceColor(Square square){
	return contains(pieces[WHITE], map(square)) ? WHITE : BLACK;
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
