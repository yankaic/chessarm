#ifndef BOARDLIB
#define BOARDLIB
#include "board.cpp"
#endif

#ifndef KINEMATICSLIB
#define KINEMATICSLIB
#include "kinematics.cpp"
#endif

const float BOARD_SQUARE = 5.5;
const float BOARD_WITHOUT_BORDER = BOARD_SQUARE * BOARD_SIZE;
const float BOARD_BORDER = 2.0;
const float BOARD_WITH_BORDER = BOARD_WITHOUT_BORDER + BOARD_BORDER * 2.0;
const float GAP_DISTANCE = 5.0;
const float HEIGHT_HIGH = 10.0;
const float HEIGHT_LOW = 5.0;
const float DEADLINETIME = 2.0;

Point3D point(Square square, bool isHigh);

Point3D* intercalate(Point3D origin, Point3D destination, const double seconds);

void move(Movement move);