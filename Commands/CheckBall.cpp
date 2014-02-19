// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "CheckBall.h"
CheckBall::CheckBall() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::lights);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void CheckBall::Initialize() {
	previousLightState = false;
}
// Called repeatedly when this Command is scheduled to run
void CheckBall::Execute() {
	//Robot::lights->SetClawLed(Robot::lights->HasBall());
	Robot::lights->Update(Robot::lights->HasBall());
	//	if(Robot::lights->HasBall() && previousLightState == false) {
	//		Robot::claw->SetWheel(false);
	//	}
	//	previousLightState = Robot::lights->HasBall();
}
// Make this return true when this Command no longer needs to run execute()
bool CheckBall::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void CheckBall::End() {

}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckBall::Interrupted() {
}
