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
	Point3D initialPosition, origin, originHigh, destination, destinationHigh;

	initialPosition.x = INITIAL_X;
	initialPosition.y = INITIAL_Y;
	initialPosition.z = INITIAL_Z;

	origin = point(move.origin, false);
	originHigh = origin;
	originHigh.z = HEIGHT_HIGH;

	destination = point(move.destination, false);
	destinationHigh = destination;
	destinationHigh.z = HEIGHT_HIGH;

	Point3D *prepareTakePath, *takePath, *returnTakePath, 
		*prepareAttackPath, *attackPath, *returnAttackPath, *returnInitialPath;

	const double prepareTakeSeconds = 2, takeSeconds = 1, returnTakeSeconds = 1, 
		prepareAttackSeconds = 2, attackSeconds = 1, returnAttackSeconds = 1, returnInitialSeconds = 3;

	prepareTakePath 	= intercalate(initialPosition, 	originHigh,				prepareTakeSeconds);
	takePath 					= intercalate(originHigh, 			origin, 					takeSeconds);
	returnTakePath 		= intercalate(origin, 					originHigh, 			returnTakeSeconds);
	prepareTakePath		= intercalate(originHigh, 			destinationHigh,	prepareTakeSeconds);
	attackPath 				= intercalate(destinationHigh,	destination, 			attackSeconds);
	returnAttackPath	= intercalate(destination, 			destinationHigh, 	returnAttackSeconds);
	returnInitialPath = intercalate(destinationHigh, 	initialPosition, 	returnInitialSeconds);

	const bool OPENED_CLAW = true;
	const bool CLOSED_CLAW = !OPENED_CLAW;

	runPath(prepareTakePath, OPENED_CLAW);
	runPath(takePath, OPENED_CLAW);
	runPath(returnTakePath, CLOSED_CLAW);
	runPath(prepareAttackPath, CLOSED_CLAW);
	runPath(attackPath, CLOSED_CLAW);
	runPath(returnAttackPath, OPENED_CLAW);
	runPath(returnInitialPath, OPENED_CLAW);
}

void runPath(Point3D *path, int size, bool claw){
	float  base,  shoulder,  elbow,  wrist;
	for(int i = 0; i < size; i++){
		base = baseAngle(path[i]);
		shoulder = shoulderAngle(path[i]);
		elbow = elbowAngle(path[i]);
		wrist = wristAngle(path[i]);
		runAngles(base, shoulder, elbow, wrist, claw);
	}
}