#include <bitset>  
using namespace std;


#define BOARD_SIZE 8 

bitset<64> setBit(bitset<64> map, int line, int column);

bitset<64> setBit(bitset<64> map, bool value, int line, int column);

bitset<64> clearBit(bitset<64> map, int line, int column);

bool getBit(bitset<64> map, int line, int column);

void printMap(bitset<64> map);

void printBoard();

int count(bitset<64> map);