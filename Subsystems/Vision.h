// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef VISION_H
#define VISION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../VisionSample2014/VisionSample2014.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class Vision: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool goalState;
public:
	AxisCamera& camera;
	VisionSample2014* visionObj;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Relay* ledSpike;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Vision();
	void InitDefaultCommand();
	bool GetGoalState();
	void SetToTeleop();
	void SetToAutonomous();
	bool Hot();
	void SetGoalState(bool state);
	void TurnOffLed();
	void TurnOnLed();
};
#endif
