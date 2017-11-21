#include "kinematics.hpp"

bool supportTest (Point3D location) {	  
	float module = sqrt(pow(location.x, 2) + pow(location.y,2));
	base = acos(location.x / module) * 180 / M_PI;

	float y = module; //front lenght	
	float wristHeight = location.z + HAND_LENGTH;	
	float distance = sqrt(pow(y, 2) + pow(wristHeight - BASE_HEIGHT, 2));	
	float wristModule = sqrt(pow(wristHeight, 2) + pow(y, 2)); //distancia base pulso.
	
	float complement1 = 
		acos(( -pow(FOREARM_LENGTH,2) + pow(distance, 2) + pow(ARM_LENGTH, 2)) / (2 * distance * ARM_LENGTH));
	float complement2 = 
		acos((-pow(wristModule, 2) + pow(distance, 2) + pow(BASE_HEIGHT, 2)) / (2 * distance * BASE_HEIGHT));
	
	shoulder = (complement1 + complement2) * 180 / M_PI -90;
	
	float realHigh = location.z - (BASE_HEIGHT - HAND_LENGTH);
	
	elbow = acos(
		(pow(ARM_LENGTH, 2) + pow(FOREARM_LENGTH, 2) - (pow(y,2) + pow(realHigh, 2)))
		/ (2 * ARM_LENGTH * FOREARM_LENGTH) ) * 180 / M_PI;
	wrist = 270 - shoulder - elbow;
	
	return !(isnan(shoulder) || isnan(elbow) || isnan(wrist) || isnan(base));
}

float baseAngle(Point3D coordinate){
	if (supportTest(coordinate)) return base;
	else return base = BASE_DEFAULT;
}

float shoulderAngle(Point3D coordinate){
	if (supportTest(coordinate)) return shoulder;
	else return shoulder = SHOULDER_DEFAULT;
}

float elbowAngle(Point3D coordinate){
	if (supportTest(coordinate)) return elbow;
	else return elbow = ELBOW_DEFAULT;
}

float wristAngle(Point3D coordinate){
	if (supportTest(coordinate)) return wrist;
	else return wrist = WRIST_DEFAULT;
}

float clawAngle(Point3D coordinate){

}