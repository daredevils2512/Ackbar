// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Angle.h"
#include "Commands/AutonDrive.h"
#include "Commands/AutonWait.h"
#include "Commands/AutonomousCommandGroup.h"
#include "Commands/CheckBall.h"
#include "Commands/ClawOpen.h"
#include "Commands/ClawSet.h"
#include "Commands/ClawSetWheel.h"
#include "Commands/CompressorOveride.h"
#include "Commands/DogControl.h"
#include "Commands/FloorSnapPressed.h"
#include "Commands/FloorSnapReleased.h"
#include "Commands/GoToAngle.h"
#include "Commands/LedTurnOn.h"
#include "Commands/PullBack.h"
#include "Commands/Release.h"
#include "Commands/RunCompressor.h"
#include "Commands/ShiftDown.h"
#include "Commands/ShiftUp.h"
#include "Commands/Shoot.h"
#include "Commands/ShootPause.h"
#include "Commands/StickDrive.h"
#include "Commands/TurnToAngle.h"
#include "Commands/Visiontrack.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include <cmath>
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	stick2 = new Joystick(2);
	
	onlyPullBack2 = new JoystickButton(stick2, 6);
	onlyPullBack2->WhenPressed(new PullBack());
	onlyPullBack = new JoystickButton(stick2, 5);
	onlyPullBack->WhenPressed(new PullBack());
	stick1 = new Joystick(1);
	
	compressorOverideButton = new JoystickButton(stick1, 3);
	compressorOverideButton->WhileHeld(new CompressorOveride());
	clawOpenButton = new JoystickButton(stick1, 5);
	clawOpenButton->WhileHeld(new ClawOpen());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("LedTurnOn", new LedTurnOn());
	SmartDashboard::PutData("ShiftUp", new ShiftUp());
	SmartDashboard::PutData("ShiftDown", new ShiftDown());
	SmartDashboard::PutData("PullBack", new PullBack());
	SmartDashboard::PutData("Release", new Release());
	SmartDashboard::PutData("Shoot", new Shoot());
	SmartDashboard::PutData("ClawSet", new ClawSet());
	SmartDashboard::PutData("ClawSetWheel", new ClawSetWheel());
	SmartDashboard::PutData("Visiontrack", new Visiontrack());
	SmartDashboard::PutData("ClawOpen", new ClawOpen());
	SmartDashboard::PutData("RunCompressor", new RunCompressor());
	SmartDashboard::PutData("CompressorOveride", new CompressorOveride());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	
	goToTruss = new JoystickButton(stick2, 4);
	goToGoal = new JoystickButton(stick2, 3);
	goToFloor = new JoystickButton(stick2, 1);
	goToTruss->WhenPressed(new GoToAngle(false, Robot::trunnion->TRUSSANGLE));
	goToGoal->WhenPressed(new GoToAngle(false, Robot::trunnion->GOALANGLE));
	goToFloor->WhenPressed(new GoToAngle(false, Robot::trunnion->FLOORANGLE));
	
	drvLeftTrigger = new TriggerButton(stick1, 3, 0.5);
	drvRightTrigger = new TriggerButton(stick1, 3, -0.5);
	accLeftTrigger = new TriggerButton(stick2, 3, 0.5);
	accRightTrigger = new TriggerButton(stick2, 3, -0.5);
	accClawTrigger = new TriggerButton(stick2, 6, 0.5);
	accClawTrigger2 = new TriggerButton(stick2, 6, -0.5);
	
	drvLeftTrigger->WhenPressed(new FloorSnapPressed());
	drvLeftTrigger->WhenReleased(new FloorSnapReleased());
	drvRightTrigger->WhenPressed(new ShiftDown());
	drvRightTrigger->WhenReleased(new ShiftUp());
	accLeftTrigger->WhenPressed(new Release());
	accRightTrigger->WhenPressed(new Shoot());
	accClawTrigger->WhenPressed(new ClawSetWheel());
	accClawTrigger2->WhenPressed(new ClawSet());
				
	SmartDashboard::PutData("GoToTrussAngle", new GoToAngle(false, Robot::trunnion->TRUSSANGLE));
	SmartDashboard::PutData("GoToFloorAngle", new GoToAngle(false, Robot::trunnion->FLOORANGLE));
	SmartDashboard::PutData("GoToGoalAngle", new GoToAngle(false, Robot::trunnion->GOALANGLE));
	SmartDashboard::PutData("Autonomous Mode 1", new AutonomousCommandGroup(1));
	SmartDashboard::PutData("Autonomous Mode 2", new AutonomousCommandGroup(2));
	
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getStick2() {
	return stick2;
}
Joystick* OI::getStick1() {
	return stick1;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
float OI::getDrvX() {
	return -1 * stick1->GetRawAxis(4);
}
float OI::getDrvY() {
	return stick1->GetRawAxis(2);
}
float OI::getAngleChange() {
	return stick2->GetRawAxis(5);
}
