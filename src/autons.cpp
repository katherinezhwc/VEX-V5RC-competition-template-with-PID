#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"

using namespace vex;


void rightAuton() {
  spinDTPosition(100, 24);
  turnForTime(100, 300);
}

void leftAuton() {
  turnPID(90, 2, 0, 0);
}

void skillsAuton() {
  drivePID(10, 0.24, 0.00012, 0.04); 
  //wait(234, msec);
  turnPID(-61, 0.456789, 0.00002 ,0.15); 
  drivePID(14.6, 0.24, 0.00012, 0.04); 
  drivePID(-9, 0.24, 0.00012, 0.04); 
  turnPID(105, 0.456789, 0.00002 ,0.15);
  drivePID(23, 0.24, 0.00012, 0.04); 
}
