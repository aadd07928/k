#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Intake = motor(PORT4, ratio18_1, true);
motor flywheel = motor(PORT7, ratio18_1, false);
motor BR = motor(PORT6, ratio18_1, false);
motor BL = motor(PORT10, ratio18_1, true);
motor indexer = motor(PORT12, ratio18_1, false);
motor FL = motor(PORT14, ratio18_1, true);
motor FR = motor(PORT20, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}