#include "bitmap.cpp"
#include <algorithm>  

struct Position{
	int line;
	int column;
};

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

const unsigned char WHITE = 'C';
const unsigned char BLACK = 'B';

bitset<64> getPawnMoves(Position location, char color);
bitset<64> getRookMoves(Position location);
bitset<64> getKnightMoves(Position location);
bitset<64> getBishopMoves(Position location);
bitset<64> getQueenMoves(Position location);
bitset<64> getKingMoves(Position location);
