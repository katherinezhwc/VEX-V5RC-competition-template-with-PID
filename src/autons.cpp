#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"

using namespace vex;


void rightAuton() {
  spinDTPosition(100, 28);
  turnForTime(75, 210);
  spinDTPosition(100, 23);
}

void leftAuton() {
  drivePID(24, 0.4, 0, 0);
}

void skillsAuton() {
  drivePID(12, 0.5, 0.003, 0.3);
  turnPID(90, 0.06, 0.001, 0.3);
  clamp();
  liftArm(30, 5);
  drivePID(-12, 0.5, 0.003, 0.3);
  turnPID(90, 0.06, 0.001, 0.3);
  drivePID(6, 0.5, 0.003, 0.3);
  clamp();
}
