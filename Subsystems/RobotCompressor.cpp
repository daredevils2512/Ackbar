// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.




#include "RobotCompressor.h"
#include "../Robotmap.h"
#include "../Commands/UpdateCompressor.h"

RobotCompressor::RobotCompressor() : Subsystem("RobotCompressor") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	compressorSpike = RobotMap::robotCompressorCompressorSpike;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void RobotCompressor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new UpdateCompressor());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void RobotCompressor::Start(){
	compressorOn = true;
}
void RobotCompressor::Stop() {
	compressorOn = false;
}
void RobotCompressor::Update() {
	if(compressorOn) {
		compressorSpike->Set(Relay::kOn);
	} else {
		compressorSpike->Set(Relay::kOff);
	}
}

