// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/DogControl.h"
Shooter::Shooter() : Subsystem("Shooter") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	winch = RobotMap::shooterWinch;
	eye = RobotMap::shooterEye;
	fireSolenoid1 = RobotMap::shooterFireSolenoid1;
	fireSolenoid2 = RobotMap::shooterFireSolenoid2;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new DogControl());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	loaded = false;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::SetWinch(float rate) {
	if(rate > 0) {
		winch->Set(rate);
	} else if(rate < 0) {
		winch->Set(rate);
	}
	else {
		winch->Set(0);
	}
}
bool Shooter::GetCocked() {
	if(eye->Get() == false) {
		loaded = true;
	}
	return !eye->Get();
}
void Shooter::NotLoaded() {
	loaded = false;
}
void Shooter::SetSolenoids(bool dir) {
	if(dir) {
		fireSolenoid1->Set(true);
		fireSolenoid2->Set(false);
	} else {
		fireSolenoid1->Set(false);
		fireSolenoid2->Set(true);	
	}
}
