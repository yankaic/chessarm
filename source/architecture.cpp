#include<iostream>

#ifndef BOARDLIB
#define BOARDLIB
#include "board.cpp"
#endif

#ifndef RECOGNIZERLIB
#define RECOGNIZERLIB
#include "recognizer.cpp"
#endif

#include "movecontrol.cpp"

void printMap(char* text){	
	std::cout << "linear: " << text << std::endl;
	for(int line = 0; line < BOARD_SIZE; line++){
		for(int column = BOARD_SIZE - 1; column >= 0; column--){
			char ch = text[line * BOARD_SIZE + column];
			if(ch == '1')
				std::cout << " *";
			else if (ch == '0')				
				std::cout << " ·";
			else						
				std::cout << ' ' << ch;
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
	printMap(toString(~map(7,7)));
}

void testMap(){
	printMap(toString(occupiedSquares));
}

void northTest(){
	printMap(toString(northwestAttacks(0, getLocation(map(3,6)))));
}

void piecesTest(){
	printMap(toString(bishopAttacks(0, getLocation(map(3,3)))));
}

void pawnAttackTest(){
	printMap(toString(pawnAttacks(0, getLocation(map(1,6)),true)));
}

void boardPrintTest(){
	printMap(boardString());
}

void movimentTest(){
	Movement move;
	move.origin = getLocation(map(1,1));
	move.destination = getLocation(map(7,1));
	recordMovement(move);

	printMap(boardString());
	std::cout << std::endl << "Peoes: ";
	printMap(toString(pieces[PAWN]));	
	printMap(toString(pieces[WHITE]));
	printMap(toString(pieces[BLACK]));
}

void testPointer(){
	printMap(toString(pieces[ROOK]));
}

void recognizeTest(){
	Movement move;
	move.origin = getLocation(map(6,1));
	move.destination = getLocation(map(5,1));
	recordMovement(move);
	move.origin = getLocation(map(0,3));
	move.destination = getLocation(map(3,4));
	recordMovement(move);
	printMap(boardString());

	Map attacks = availableAttacks(move.destination);
	printMap(toString(attacks));
}

void recognTest(){
	Map newoccupation = 0xFFFF00000001FEFF;
	Map modifications = occupiedSquares ^ newoccupation;
	Map originmap = modifications & occupiedSquares;
	Map destinationmap = modifications ^ originmap;

	printMap(toString(occupiedSquares));
	printMap(toString(newoccupation));
	printMap(toString(modifications));
	printMap(toString(originmap));
	printMap(toString(destinationmap));
}

void kinematicsTest(){
	using namespace std;
	Point3D location;
	location.x = 14;
	location.y = 60;
	location.z = 16;

	supportTest(location);
	cout << "x=" << location.x << " y=" << location.y << " z=" << location.z << endl;
	cout << "base: " << baseAngle(location) << endl;
	cout << "ombro: " << shoulderAngle(location) << endl;
	cout << "cotovelo: " << elbowAngle(location) << endl;
	cout << "pulso: " << wristAngle(location) << endl;
}

void moveTest(){
	Square square;
	square.line = 0;
	square.column = 4;
	Point3D location = point(square, true);
	using namespace std;
	cout << "x=" << location.x << "\ty=" << location.y << "\tz=" << location.z << endl;
}

void moveArrayTest(){
	Square origin = getLocation(map(0,0));
	Square destination = getLocation(map(7,7));
	Point3D from = point(origin, true);
	Point3D to = point(destination, true);
	Point3D *points = intercalate(from, to,2.0);

	using namespace std;
	for(int i = 0; i < 60; i++){
		Point3D location = points[i];
		cout << "x=" << location.x << " y=" << location.y << " z=" << location.z << endl;
	}
}

void pointTest(){
	Point3D point1, point2;
	point1.x= 5;
	point1.y = 5;
	point1.z = 5;

	point2 = point1;
	point2.x = 10;

	using namespace std;
	cout << "x=" << point1.x << " y=" << point1.y << " z=" << point1.z << endl;
	cout << "x=" << point2.x << " y=" << point2.y << " z=" << point2.z << endl;
}

int variable = 4;
void contextTest(){
	int variable = 5;
	using namespace std;
}
int main(){
	contextTest();
}
