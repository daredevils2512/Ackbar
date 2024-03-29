// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "CompressorSubsystem.h"
#include "../Robotmap.h"
#include "../Commands/RunCompressor.h"
CompressorSubsystem::CompressorSubsystem() : Subsystem("CompressorSubsystem") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	compressorSpike = RobotMap::compressorSubsystemCompressorSpike;
	compressorPressureSwitch = RobotMap::compressorSubsystemCompressorPressureSwitch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
void CompressorSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new RunCompressor());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void CompressorSubsystem::On() {
//	compressor1->Start();
	compressorSpike->Set(Relay::kForward);
}
void CompressorSubsystem::Off() {
//	compressor1->Stop();
	compressorSpike->Set(Relay::kOff);
}
bool CompressorSubsystem::Pressurized() {
	return compressorPressureSwitch->Get();
}
