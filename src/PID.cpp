#include "autons.h"
#include "robot-config.h"
#include "vex.h"
#include "functions.h"
#include "PID.h"

using namespace vex;


void drivePID(double targetInches, double kP = 0.7, double kI = 0.7, double kD = 1.8) {

  double targetDegrees = inchesToDegrees(targetInches);

  setDTPosition(0); //reset encoders

  double error = targetDegrees;
  double integral = 0;
  double derivative = 0;
  double lastError = 0;
  double maxIntegral = 100;


  while (fabs(error) > 4.0) { //Keep running until you’re within 1° of your target
    double leftAvg = (LF.position(degrees) + LM.position(degrees) + LB.position(degrees)) / 3.0;
    double rightAvg = (RF.position(degrees) + RM.position(degrees) + RB.position(degrees)) / 3.0;
    double avgPos = (leftAvg + rightAvg) / 2.0;

    /*Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print(leftAvg);*/
    error = targetDegrees - avgPos;
    integral += error;

    // Anti-windup
    if (integral > maxIntegral) integral = maxIntegral;
    if (integral < -maxIntegral) integral = -maxIntegral;

    derivative = error - lastError;
    lastError = error;

    double power = (kP * error) + (kI * integral) + (kD * derivative);

    // Clamp output
    if (power > 100) power = 100;
    if (power < -100) power = -100;

    spinDT(power*0.7);

    task::sleep(20); // small loop delay
  }

  stopDT();


}

//WARNING:kP, kI, and kD values are not correct, need to update yourself
void turnPID(double targetAngle, double kP = 0.12, double kI = 0.3, double kD = 0.24) {
  
  double dir =targetAngle/fabs(targetAngle);
 
  // Reset inertial and motor encoders
  InertialSensor.setRotation(0, degrees);

  // PID state
  double err = targetAngle;
  double integ = 0;
  double deriv = 0;
  double last = 0;
  const double maxI = 50.0;

  targetAngle = fabs(targetAngle);


  // loop til we’re close
  while (fabs(err) > 3.5) {
    err = targetAngle - fabs(InertialSensor.rotation(degrees));
    integ += err;
    if (integ >  maxI) integ =  maxI;
    if (integ < -maxI) integ = -maxI;
    deriv = err - last;
    last  = err;

    double power = kP*err + kI*integ + kD*deriv;
    if (power > 100) power = 100;
    if (power < -100) power = -100;

    spinLeftDT(dir*-power);
    spinRightDT(dir*power);

    vex::task::sleep(20);
  }

  stopDT();

}