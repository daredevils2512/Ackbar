// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "TurnToAngle.h"
#include <cmath>
TurnToAngle::TurnToAngle(bool relative, float ang) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	if(relative) {
		
		angle = Robot::drivetrain->GetDirection() + ang;
	}
	else {
		angle = ang;
	}
}
// Called just before this Command runs the first time
void TurnToAngle::Initialize() {
	Robot::drivetrain->DistanceReset();
}
// Called repeatedly when this Command is scheduled to run
void TurnToAngle::Execute() {
	if(fabs(Robot::drivetrain->GetDirection() - angle) > 5) {
		if(Robot::drivetrain->GetDirection() > angle) {
			Robot::drivetrain->Turn(0.4);
		}
		else {
			Robot::drivetrain->Turn(-0.4);
		}
	}
}
// Make this return true when this Command no longer needs to run execute()
bool TurnToAngle::IsFinished() {
	if((fabs(Robot::drivetrain->GetDirection() - angle) < 5)) {
		return true;
	}
	else {
		return false;
	}
}
// Called once after isFinished returns true
void TurnToAngle::End() {
	Robot::drivetrain->Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnToAngle::Interrupted() {
}
