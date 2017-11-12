#include "bitmap.hpp"

void printMap(bitset<64> map){
	for(int index = 0; index < map.size(); index++){
		cout << (map.test(index) ? 'x' : '.') << ' ';
		if((index+1) % BOARD_SIZE == 0)
			cout << endl;
	}
	cout << endl;
}

bitset<64> setBit(bitset<64> map, int line, int column){
	return setBit(map, true, line, column);
}

bitset<64> clearBit(bitset<64> map, int line, int column){
	return setBit(map, false, line, column);
}

bool getBit(bitset<64> map, int line, int column){
	return map.test(line * BOARD_SIZE + column);
}


bitset<64> setBit(bitset<64> map, bool value, int line, int column){
	if(line < BOARD_SIZE && column < BOARD_SIZE && line >= 0 && column >= 0)
		map.set(line * BOARD_SIZE + column, value);
	return map;
}

int count(bitset<64> map){
	int counter = 0;
	for(int i = 0; i < map.size(); i++){
		if(map.test(i))
			counter++;
	}
	return counter;
}

bitset<64> getMap(unsigned char board[8][8]){
	bitset<64> map;
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = 0; column < BOARD_SIZE; column++){
			map = setBit(map, board[line][column] != 0, line, column);
		}
	}
	return map;
}