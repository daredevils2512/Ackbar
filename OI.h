// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include "TriggerButton.h"
class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Joystick* stick2;
	JoystickButton* catchButton;
	JoystickButton* stick2WinchReverse;
	JoystickButton* onlyPullBack2;
	JoystickButton* onlyPullBack;
	Joystick* stick1;
	JoystickButton* runCompressorButton;
	JoystickButton* reverseWinchButton;
	JoystickButton* compressorOverideButton;
	JoystickButton* clawOpenButton;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	JoystickButton* goToTruss;
	JoystickButton* goToGoal;
	JoystickButton* goToMidZone;
	JoystickButton* goToFloor;
	TriggerButton* drvLeftTrigger;
	TriggerButton* drvRightTrigger;
	TriggerButton* accLeftTrigger;
	TriggerButton* accRightTrigger;
	TriggerButton* accClawTrigger;
	TriggerButton* accClawTrigger2;
public:
	OI();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	Joystick* getStick1();
	Joystick* getStick2();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	float getDrvX();
	float getDrvY();
	float getAngleChange();
	float getScoopWheelStick();
};
#endif
