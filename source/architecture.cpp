#include<iostream>
#include "Test.cpp"
#include "board.cpp"
void run();


int main(){
	bool debugMode = false;
	if(debugMode)
		test();
	else
		run();	
}

void printMap(char* text){	
	std::cout << "line: " << text << std::endl;
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = BOARD_SIZE-1; column >= 0; column--){
			char ch = text[line*BOARD_SIZE+column];
			std::cout << (ch == '1'? " X" : " ·");
		}		
		std::cout << std::endl;
	}
}

void testCount(){
	std::cout << "count: " << count(0) << std::endl;
}

void testLocation(){
	Square sq = getLocation(map(9,7));
	std::cout << "line: " << sq.line << " column: " << sq.column << std::endl;
}

void testBitmap(){
	printMap(toString(map(9,7)));
}

void testMap(){
	printMap(toString(bishopPieces));
}

void run(){
	testCount();
}
