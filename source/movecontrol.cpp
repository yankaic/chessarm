#include "movecontrol.hpp"

Point3D point(Square square, bool high){
	Point3D location; //colocando a peca na posicao a0
	location.x = BOARD_SQUARE * -3.5;
	location.y = GAP_DISTANCE + BOARD_BORDER + BOARD_SQUARE / 2;
	location.z = high ? HEIGHT_HIGH : HEIGHT_LOW;

	//colocando na posicao de acordo com square
	location.x += square.column * BOARD_SQUARE;
	location.y += square.line * BOARD_SQUARE;
	return location;
}	

void move(Movement move){
	
}