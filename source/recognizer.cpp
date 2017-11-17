Movement movement(Map newoccupation){

}

Map availableAttacks(Square origin){
	int type = pieceType(origin);
	int color = pieceColor(origin);
	int otherColor = 1 - color;

	Map attacks;
	switch(type){
		case PAWN:
			attacks = pawnAttacks(occupiedSquares, origin, color == WHITE);
			break;

		case ROOK:
			attacks = rookAttacks(occupiedSquares, origin);
			break;

		case KNIGHT:
			attacks = knightAttacks(occupiedSquares, origin);
			break;

		case BISHOP:
			attacks = bishopAttacks(occupiedSquares, origin);
			break;

		case QUEEN:
			attacks = queenAttacks(occupiedSquares, origin);
			break;

		case KING:
			attacks = kingAttacks(occupiedSquares, origin);
			break;

		default:
			attacks = 0;
	}

	return attacks & pieces[otherColor];	//ataca apenas pecas do oponente
}