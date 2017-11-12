#include <bitset>  

#ifndef BOARDINCLUDE
#define BOARDINCLUDE
#include "board.cpp"
#endif

#ifndef NAMESTD
#define NAMESTD
#include <iostream>
using namespace std;
#endif


#define BOARD_SIZE 8 

bitset<64> getMap(unsigned char board[8][8]);

bitset<64> setBit(bitset<64> map, int line, int column);

bitset<64> setBit(bitset<64> map, bool value, int line, int column);

bitset<64> clearBit(bitset<64> map, int line, int column);

bool getBit(bitset<64> map, int line, int column);

void printMap(bitset<64> map);

void printBoard();

int count(bitset<64> map);