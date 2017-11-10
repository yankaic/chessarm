#include "architecture.hpp"
#include "Teste.cpp"

int main(){
	Position from;
	from.column = 0;
	from.line = 1;

	Position to;
	to.column = 0;
	to.line = 2;

	Movement move;
	move.origin = from;
	move.destination = to;

	printBoard();
	recordMovement(move);
	cout << endl;
	printBoard();

	string mapstring = "";
	mapstring += "11111111";
	mapstring += "10111111";
	mapstring += "01000000";
	mapstring += "00000000";
	mapstring += "00000000";
	mapstring += "00000001";
	mapstring += "11111110";
	mapstring += "11111111";
	bitset<64> map(mapstring);	
	recognize(map);
}
