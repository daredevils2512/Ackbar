// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "GoToAngle.h"
#include <cmath>
const float GoToAngle::highMargin = 0.1;
const float GoToAngle::lowMargin = 0.025;
GoToAngle::GoToAngle(bool relative, float ang) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::trunnion);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SetInterruptible(true);
	if(relative) {
		angle = Robot::trunnion->GetAngle() + ang;
	}
	else {
		angle = ang;
	}
}
// Called just before this Command runs the first time
void GoToAngle::Initialize() {
	angleReached = false;
}
// Called repeatedly when this Command is scheduled to run
void GoToAngle::Execute() {
	if(Robot::trunnion->GetAngle() > 0.5) {
		if(GetDistance() > highMargin) {
			RunAngleMotors(0.9);
		} else {
			angleReached = true;
			Robot::trunnion->SetAngleMotors(0);
		}
	}
	else {
		if(GetDistance() > lowMargin) {
			RunAngleMotors(0.7);
		} else {
			angleReached = true;
			Robot::trunnion->SetAngleMotors(0);
		}
	}
}
// Make this return true when this Command no longer needs to run execute()
bool GoToAngle::IsFinished() {
	return angleReached;
}
// Called once after isFinished returns true
void GoToAngle::End() {
	Robot::trunnion->SetAngleMotors(0);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoToAngle::Interrupted() {
}
float GoToAngle::GetDistance() {
	return fabs(Robot::trunnion->GetAngle() - angle);
}
void GoToAngle::RunAngleMotors(float speed) {
	if(GetDistance() > 0.3) {
		if(Robot::trunnion->GetAngle() > angle) {
			Robot::trunnion->SetAngleMotors(-speed);
		} else {
			Robot::trunnion->SetAngleMotors(speed);
		}
	} else {
		if(Robot::trunnion->GetAngle() > angle) {
			Robot::trunnion->SetAngleMotors(0.6 * -speed);
		} else {
			Robot::trunnion->SetAngleMotors(0.6 * speed);
		}
	}
}
