#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"
#include "autons.h"

using namespace vex;


//red left side of the field//
void rightAuton() 
{
runIntake();
  drivePID(20, 0.15, 0, 0.01);
turnPID(-130, 0.15, 0, 0);
drivePID(40, 0.15, 0, 0.01);
//stopIntake();
//runIntake();
void rightAuton() {
  spinDTPosition(100, 24);
  turnForTime(100, 300);
}



void leftAuton() {
  drivePID(24, 0.19, 0, 0);
  turnPID(-62, 0.8, 0, 0);
  drivePID(24.5, 0.19, 0, 0);
  turnPID(63, 0.8, 0, 0);
  
  turnPID(90, 2, 0, 0);
}
void skillsAuton() {
  drivePID(12, 0.5, 0.0, 0.0);
  turnPID(90, 0.06, 0.001, 0.3);
  drivePID(-12, 0.5, 0.003, 0.3);
  turnPID(90, 0.06, 0.001, 0.3);
  drivePID(6, 0.5, 0.003, 0.3);
  drivePID(10, 0.24, 0.00012, 0.04); 
  //wait(234, msec);
  turnPID(-61, 0.456789, 0.00002 ,0.15); 
  drivePID(14.6, 0.24, 0.00012, 0.04); 
  drivePID(-9, 0.24, 0.00012, 0.04); 
  turnPID(105, 0.456789, 0.00002 ,0.15);
  drivePID(23, 0.24, 0.00012, 0.04); 
}


  


