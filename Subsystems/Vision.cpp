// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Vision.h"
#include "../Robotmap.h"
#include "../Commands/CameraLedUpdate.h"
Vision::Vision() :
	Subsystem("Vision"), camera(AxisCamera::GetInstance("10.25.12.11")),
			visionObj(new VisionSample2014)
	{
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ledSpike = RobotMap::visionledSpike;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ledon = false;
}
void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
bool Vision::GetGoalState() {
	return goalState;
}
void Vision::SetToTeleop() {
	camera.WriteBrightness(50);
}
void Vision::SetToAutonomous() {
	camera.WriteBrightness(25);
}
bool Vision::Hot() {
	return visionObj->ProcessImage();
}
void Vision::SetGoalState(bool state) {
	goalState = state;
}
void Vision::UpdateLedRing() {
	if(ledon) {
		ledSpike->Set(Relay::kForward);
	}else{
		ledSpike->Set(Relay::kOff);
	}
}
void Vision::SetLedRing(bool on) {
	ledon = on;
}
void Vision::SetLedRingDirectly(bool on) {
	if(on) {
		ledSpike->Set(Relay::kForward);
	}
	else {
		ledSpike->Set(Relay::kOff);
	}
}
