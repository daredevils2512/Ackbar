// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Catch.h"
#
Catch::Catch() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::vision);
	Requires(Robot::claw);
}
// Called just before this Command runs the first time
void Catch::Initialize() {
	Robot::claw->SetClaw(true);
	Robot::claw->SetWheelSpeed(1);
}
// Called repeatedly when this Command is scheduled to run
void Catch::Execute() {
    bool flashState = static_cast<int>(TimeSinceInitialized() * FLASH_FREQUENCY) % 2;
    Robot::vision->SetLedRingDirectly(flashState);
}
// Make this return true when this Command no longer needs to run execute()
bool Catch::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void Catch::End() {
	Robot::claw->SetClaw(false);
	Robot::claw->SetWheelSpeed(0.4);
	Robot::vision->SetLedRingDirectly(false);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Catch::Interrupted() {
	End();
}
