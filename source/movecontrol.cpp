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


Point3D* intercalate(Point3D origin, Point3D destination, const double seconds){
	Point3D difference;
	difference.x = destination.x - origin.x;
	difference.y = destination.y - origin.y;
	difference.z = destination.z - origin.z;

	Point3D point;
	const int frequency = 30;
	Point3D *pointers = new Point3D[(int)(frequency * seconds)]; 

	double scale = 0, increment = 1.0 / (frequency * seconds);

	for(int i = 0; scale <= 1; scale += increment, i++){
		point.x = origin.x + difference.x * scale;
		point.y = origin.y + difference.y * scale;
		point.z = origin.z + difference.z * scale;
		pointers[i] = point;
	}
	point.x = origin.x + difference.x * scale;
	point.y = origin.y + difference.y * scale;
	point.z = origin.z + difference.z * scale;
	pointers[(int)(frequency * seconds) -1] = point;

	return pointers;
}

void move(Movement move){
	
}