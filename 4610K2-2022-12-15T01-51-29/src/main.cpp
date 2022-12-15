/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Intake               motor         4               
// flywheel             motor         7               
// BR                   motor         6               
// BL                   motor         10              
// indexer              motor         12              
// FL                   motor         14              
// FR                   motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void foward(int target){
  FL.spinFor(forward, target, degrees, false);
  FR.spinFor(forward, target, degrees, false);
  BR.spinFor(forward, target, degrees, false);
  BL.spinFor(forward, target, degrees, true);
}

void backwards(int target){
  FL.spinFor(reverse, target, degrees, false);
  FR.spinFor(reverse, target, degrees, false);
  BR.spinFor(reverse, target, degrees, false);
  BL.spinFor(reverse, target, degrees, true);
}

void turnR(int target){
  FL.spinFor(forward, target, degrees, false);
  FR.spinFor(reverse, target, degrees, false);
  BR.spinFor(reverse, target, degrees, false);
  BL.spinFor(forward, target, degrees, true);
}

void turnL(int target){
  FL.spinFor(reverse, target, degrees, false);
  FR.spinFor(forward, target, degrees, false);
  BR.spinFor(forward, target, degrees, false);
  BL.spinFor(reverse, target, degrees, true);
}
void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  foward(100);
  BR.stop();
  FR.stop();
  FL.setVelocity(100, percent);
  BL.setVelocity(100, percent);
  while (FL.position(degrees)>=1400){
    FL.spin(forward);
    BL.spin(forward);
  }
BL.stop();
FL.stop();
  FL.setVelocity(50, percent);
  BL.setVelocity(50, percent);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int inswitch=0;
int flyswitch=0;
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
//driver of the tank variety.
FL.spin(forward, Controller1.Axis3.position(percent), pct),
BL.spin(forward, Controller1.Axis3.position(percent), pct),
FR.spin(forward, Controller1.Axis2.position(percent), pct),
BR.spin(forward, Controller1.Axis2.position(percent), pct);
//DONT SPAM THIS, sometimes it jams
if(Controller1.ButtonL1.pressing()){
  indexer.setVelocity(100, percent);
  indexer.spinFor(forward, 0.1, turns);
  indexer.spinFor(reverse, 0.1, turns);
  wait(1,msec);
  indexer.stop();
}

//intake
 if (Controller1.ButtonR2.pressing()){
    inswitch=inswitch+1;
    if(inswitch==2){
      inswitch=inswitch-2;
    }
    Intake.stop();
    if(inswitch==1){
      Intake.setVelocity(100,percent);
      Intake.spin(forward);
    }
  }

  

//flywheel
if (Controller1.ButtonR1.pressing()){
    flyswitch=flyswitch+1;
    if(flyswitch==2){
      flyswitch=flyswitch-2;
    }
    flywheel.stop();
    if(flyswitch==1){
      flywheel.setVelocity(100,percent);
      flywheel.spin(forward);
    }
  }

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
//
// Main will set up the competition functions and callbacks.



int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
