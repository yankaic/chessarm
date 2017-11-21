
const float BASE_HEIGHT = 18.0;
const float ARM_LENGTH = 23.0;
const float FOREARM_LENGTH = 23.25;
const float HAND_LENGTH = 15;

const float OPENED_CLAW = 90;
const float CLOSED_CLAW = 90;

const float BASE_DEFAULT = 90;
const float SHOULDER_DEFAULT = 90;
const float ELBOW_DEFAULT = 90;
const float WRIST_DEFAULT = 90;
const float CLAW_DEFAULT = OPENED_CLAW;

float base = BASE_DEFAULT;
float shoulder = SHOULDER_DEFAULT;
float elbow = ELBOW_DEFAULT;
float wrist = WRIST_DEFAULT;
float claw = CLAW_DEFAULT;

struct Point3D{
	double x;
	double y;
	double z;
};

bool supportTest(Point3D coordinate);

float baseAngle(Point3D coordinate);

float shoulderAngle(Point3D coordinate);

float elbowAngle(Point3D coordinate);

float wristAngle(Point3D coordinate);

float clawAngle(Point3D coordinate);