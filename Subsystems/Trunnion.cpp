// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include <cmath>
#include "Trunnion.h"
#include "../Robotmap.h"
#include "../Commands/Angle.h"
const float Trunnion::GOALANGLE = 2.501;
//2.234
//2.8
//1.92
const float Trunnion::MIDZONEANGLE = 2.7;
//2.4
const float Trunnion::TRUSSANGLE = 3.803;
//3.2
const float Trunnion::ONEPOINTANGLE = 1.0;
//0.5
const float Trunnion::FLOORANGLE = 0.191;
//0.01
const float Trunnion::MINANGLE = 0.171;
//0
const float Trunnion::MAXANGLE = 3.803;
//4.199
//3.3, 2.8
const float Trunnion::AUTON1ANGLE = 2.352;
//2.352
const float Trunnion::AUTON2ANGLE = 2.027;
//2.027
const float Trunnion::CROSSSHOT = 2.9;
Trunnion::Trunnion() : Subsystem("Trunnion") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	armMotor1 = RobotMap::trunnionArmMotor1;
	armMotor2 = RobotMap::trunnionArmMotor2;
	armAngle = RobotMap::trunnionArmAngle;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
void Trunnion::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Angle());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
float Trunnion::GetAngle() {
	float angle = armAngle->GetAverageVoltage();
	if(angle < 0) {
		angle = MAXANGLE;
	}
	return angle;
}
void Trunnion::SetAngleMotors(float rate) {
	if(fabs(rate) > 0) {
//		if(GetAngle() > MINANGLE && rate < 0) {
			armMotor1->Set(rate);
			armMotor2->Set(rate);
//		}
//		if(GetAngle() < MAXANGLE && rate > 0) {
//			armMotor1->Set(rate);
//			armMotor2->Set(rate);
//		}
	}
	else {
		armMotor1->Set(0);
		armMotor2->Set(0);
	}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
