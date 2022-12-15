using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Intake;
extern motor flywheel;
extern motor BR;
extern motor BL;
extern motor indexer;
extern motor FL;
extern motor FR;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );