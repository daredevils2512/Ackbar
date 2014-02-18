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
#include <sstream>

const float TurnToAngle::TOLERANCE = 3;
const float TurnToAngle::RATE = 0.4;

TurnToAngle::TurnToAngle(bool relative, float ang) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	ostringstream message;
	message << "TurnToAngle Constructor relative: " << relative << " ang: " << ang;
	Robot::Log(message.str());
	message.clear();
	if(relative) {
		angle = Robot::drivetrain->GetDirection() + ang;
		if(ang < 0) {
			direction = RIGHT;
		}
		else {
			direction = LEFT;
		}
	}
	else {
		angle = ang;
		if(Robot::drivetrain->GetDirection() > angle) {
			direction = RIGHT;
		}
		else {
			direction = LEFT;
		}
	}
	message << "TurnToAngle Constructor direction: " << direction << " angle: " << angle;
	Robot::Log(message.str());
	message.clear();
}
// Called just before this Command runs the first time
void TurnToAngle::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void TurnToAngle::Execute() {
	Robot::drivetrain->Turning(RATE * direction);
}
// Make this return true when this Command no longer needs to run execute()
bool TurnToAngle::IsFinished() {
	float gyroVal = Robot::drivetrain->GetDirection();
	float difference = gyroVal - angle;
	ostringstream message;
	message << "TurnToAngle IsFinished: "  << difference << " GetDirection: " << gyroVal;
	Robot::Log(message.str());
	message.clear();
	if(direction == LEFT) {
		if(difference > -TOLERANCE) {
			message << "TurnToAngle IsFinished difference > -tolerance FINISHED";
			Robot::Log(message.str());
			message.clear();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if(difference < TOLERANCE) {
			message << "TurnToAngle IsFinished difference < tolerance FINISHED";
			Robot::Log(message.str());
			message.clear();
			return true;
		}
		else {
			return false;
		}
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
