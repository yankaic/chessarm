#include "board.hpp"

char* toString(Map map){
	int i = 63;
	char* text = new char[65];
	text[64] = '\0';
	Map mostSig = 0x8000000000000000;

	for(int i = 0; i < 64; i++){
		text[i] = (map & mostSig) !=0 ? '1' : '0';
		map = map << 1;
	}
	return text;
}