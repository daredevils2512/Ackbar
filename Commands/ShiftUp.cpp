// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "ShiftUp.h"
ShiftUp::ShiftUp() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void ShiftUp::Initialize() {
	SetInterruptible(false);
	SetTimeout(1);
	Robot::drivetrain->Stop();
}
// Called repeatedly when this Command is scheduled to run
void ShiftUp::Execute() {
	if(TimeSinceInitialized() > 0.5) {
		Robot::drivetrain->Shift(true);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool ShiftUp::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void ShiftUp::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftUp::Interrupted() {
}