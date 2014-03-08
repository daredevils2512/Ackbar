// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Claw.h"
#include "../Robotmap.h"
#include "../Commands/UpdateClawWheel.h"
Claw::Claw() : Subsystem("Claw") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	clawWheel = RobotMap::clawClawWheel;
	clawSolenoid = RobotMap::clawClawSolenoid;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
void Claw::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new UpdateClawWheel());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	clawWheelSpeed = 0;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Claw::SetClaw(bool dir) {
	clawSolenoid->Set(dir);
}
bool Claw::GetClaw() {
	return clawSolenoid->Get();
}
void Claw::SetWheelSpeed(float speed) {
	clawWheelSpeed = speed;
	clawWheel->Set(speed);
}
void Claw::UpdateWheel() {
	clawWheel->Set(clawWheelSpeed);
}
void Claw::Toggle() {
	if(clawWheelSpeed != 0) {
		clawWheelSpeed = 0;
	} else {
		clawWheelSpeed = -1.0;
	}
}
void Claw::Stop() {
	clawWheelSpeed = 0;
}
