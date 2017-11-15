



Position getOrigin(bitset<64> map); //ok
Position getMovement(bitset<64> map);

Position getDestination(bitset<64> map);

Position discoverMovement(Position origin);

bitset<64> getPossibleMoves(Position origin); //ok

bitset<64> getAvailableMoves(Position origin, bitset<64> possibleMoves);

bitset<64> getAvailableAttacks(Position origin, bitset<64> possibleMoves);






