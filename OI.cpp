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
#include "Commands/AutonomousCommand.h"
#include "Commands/ClawSet.h"
#include "Commands/ClawSetWheel.h"
#include "Commands/GoToAngle.h"
#include "Commands/PullBack.h"
#include "Commands/Release.h"
#include "Commands/ShiftDown.h"
#include "Commands/ShiftUp.h"
#include "Commands/Shoot.h"
#include "Commands/ShootPause.h"
#include "Commands/StickDrive.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	stick1 = new Joystick(1);
	
	clawWheelToggleButton = new JoystickButton(stick1, 5);
	clawWheelToggleButton->WhenPressed(new ClawSetWheel());
	clawToggleButton = new JoystickButton(stick1, 3);
	clawToggleButton->WhenPressed(new ClawSet());
	onlyPullBack = new JoystickButton(stick1, 7);
	onlyPullBack->WhenPressed(new PullBack());
	onlyShootButton = new JoystickButton(stick1, 8);
	onlyShootButton->WhenPressed(new Release());
	shootButton = new JoystickButton(stick1, 2);
	shootButton->WhenPressed(new Shoot());
	angleDownButton = new JoystickButton(stick1, 1);
	angleDownButton->WhileHeld(new AngleDown());
	angleUpButton = new JoystickButton(stick1, 4);
	angleUpButton->WhileHeld(new AngleUp());
	shiftButton2 = new JoystickButton(stick1, 6);
	shiftButton2->WhenReleased(new ShiftDown());
	shiftButton1 = new JoystickButton(stick1, 6);
	shiftButton1->WhenPressed(new ShiftUp());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("ShiftUp", new ShiftUp());
	SmartDashboard::PutData("ShiftDown", new ShiftDown());
	SmartDashboard::PutData("AngleUp", new AngleUp());
	SmartDashboard::PutData("AngleDown", new AngleDown());
	SmartDashboard::PutData("PullBack", new PullBack());
	SmartDashboard::PutData("Release", new Release());
	SmartDashboard::PutData("Shoot", new Shoot());
	SmartDashboard::PutData("ShootPause", new ShootPause());
	SmartDashboard::PutData("ClawSet", new ClawSet());
	SmartDashboard::PutData("ClawSetWheel", new ClawSetWheel());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	SmartDashboard::PutNumber("ArmAngle", Robot::trunnion->GetAngle());
	SmartDashboard::PutBoolean("ArmWheel", Robot::claw->GetWheel());
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getStick1() {
	return stick1;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
