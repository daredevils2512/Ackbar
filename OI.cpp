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
#include "Commands/AngleDown.h"
#include "Commands/AngleUp.h"
#include "Commands/AutonDrive.h"
#include "Commands/AutonWait.h"
#include "Commands/AutonomousCommandGroup.h"
#include "Commands/CheckBall.h"
#include "Commands/ClawOpen.h"
#include "Commands/ClawSet.h"
#include "Commands/ClawSetWheel.h"
#include "Commands/GoToAngle.h"
#include "Commands/PullBack.h"
#include "Commands/Release.h"
#include "Commands/RunCompressor.h"
#include "Commands/ShiftDown.h"
#include "Commands/ShiftUp.h"
#include "Commands/Shoot.h"
#include "Commands/ShootPause.h"
#include "Commands/StickDrive.h"
#include "Commands/StopCompressor.h"
#include "Commands/ToggleLED.h"
#include "Commands/TurnToAngle.h"
#include "Commands/UpdateCompressor.h"
#include "Commands/Visiontrack.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include <cmath>
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	stick2 = new Joystick(2);
	
	clawWheelToggleButton = new JoystickButton(stick2, 5);
	clawWheelToggleButton->WhenPressed(new ClawSetWheel());
	clawToggleButton = new JoystickButton(stick2, 3);
	clawToggleButton->WhenPressed(new ClawSet());
	onlyPullBack = new JoystickButton(stick2, 7);
	onlyPullBack->WhenPressed(new PullBack());
	onlyShootButton = new JoystickButton(stick2, 8);
	onlyShootButton->WhenPressed(new Release());
	shootButton = new JoystickButton(stick2, 2);
	shootButton->WhenPressed(new Shoot());
	angleDownButton = new JoystickButton(stick2, 1);
	angleDownButton->WhileHeld(new AngleDown());
	angleUpButton = new JoystickButton(stick2, 4);
	angleUpButton->WhileHeld(new AngleUp());
	stick1 = new Joystick(1);
	
	driverShoot = new JoystickButton(stick1, 1);
	driverShoot->WhenPressed(new Shoot());
	clawOpenButton = new JoystickButton(stick1, 5);
	clawOpenButton->WhileHeld(new ClawOpen());
	ledToggleButton = new JoystickButton(stick1, 3);
	ledToggleButton->WhenPressed(new ToggleLED());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("StopCompressor", new StopCompressor());
	SmartDashboard::PutData("RunCompressor", new RunCompressor());
	SmartDashboard::PutData("ShiftUp", new ShiftUp());
	SmartDashboard::PutData("ShiftDown", new ShiftDown());
	SmartDashboard::PutData("AngleUp", new AngleUp());
	SmartDashboard::PutData("AngleDown", new AngleDown());
	SmartDashboard::PutData("PullBack", new PullBack());
	SmartDashboard::PutData("Release", new Release());
	SmartDashboard::PutData("Shoot", new Shoot());
	SmartDashboard::PutData("ClawSet", new ClawSet());
	SmartDashboard::PutData("ClawSetWheel", new ClawSetWheel());
	SmartDashboard::PutData("Visiontrack", new Visiontrack());
	SmartDashboard::PutData("ToggleLED", new ToggleLED());
	SmartDashboard::PutData("ClawOpen", new ClawOpen());
	SmartDashboard::PutData("UpdateCompressor", new UpdateCompressor());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	
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
