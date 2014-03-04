// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "LedTurnOff.h"
LedTurnOff::LedTurnOff() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::vision);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void LedTurnOff::Initialize() {
	Robot::vision->SetLedRingDirectly(false);
}
// Called repeatedly when this Command is scheduled to run
void LedTurnOff::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool LedTurnOff::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void LedTurnOff::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LedTurnOff::Interrupted() {
}
