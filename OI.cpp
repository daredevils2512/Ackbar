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
#include "Commands/ActivatePhotonCannon.h"
#include "Commands/Angle.h"
#include "Commands/AutonDrive.h"
#include "Commands/AutonWait.h"
#include "Commands/AutonWheelSet.h"
#include "Commands/AutonomousCommandGroup.h"
#include "Commands/CameraLedUpdate.h"
#include "Commands/Catch.h"
#include "Commands/CheckBall.h"
#include "Commands/ClawOpen.h"
#include "Commands/ClawSet.h"
#include "Commands/ClawSetWheel.h"
#include "Commands/ClawWheelToggle.h"
#include "Commands/CompressorOveride.h"
#include "Commands/DeleteLog.h"
#include "Commands/DogControl.h"
#include "Commands/FloorSnapPressed.h"
#include "Commands/FloorSnapReleased.h"
#include "Commands/GoToAngle.h"
#include "Commands/LedTurnOff.h"
#include "Commands/LedTurnOn.h"
#include "Commands/PullBack.h"
#include "Commands/Release.h"
#include "Commands/ReverseWinch.h"
#include "Commands/RunCompressor.h"
#include "Commands/SetCameraForAuton.h"
#include "Commands/SetCameraForTeleop.h"
#include "Commands/SetClawLedandRing.h"
#include "Commands/ShiftDown.h"
#include "Commands/ShiftUp.h"
#include "Commands/Shoot.h"
#include "Commands/ShootPause.h"
#include "Commands/StickDrive.h"
#include "Commands/Turn.h"
#include "Commands/TurnToAngle.h"
#include "Commands/UpdateClawWheel.h"
#include "Commands/Visiontrack.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include <cmath>
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	stick2 = new Joystick(2);
	
	catchButton = new JoystickButton(stick2, 5);
	catchButton->WhileHeld(new Catch());
	stick2WinchReverse = new JoystickButton(stick2, 7);
	stick2WinchReverse->WhenPressed(new ReverseWinch());
	onlyPullBack2 = new JoystickButton(stick2, 6);
	onlyPullBack2->WhenPressed(new PullBack());
	onlyPullBack = new JoystickButton(stick2, 7);
	onlyPullBack->WhenPressed(new PullBack());
	stick1 = new Joystick(1);
	
	driverPullBack = new JoystickButton(stick1, 3);
	driverPullBack->WhenPressed(new PullBack());
	runCompressorButton = new JoystickButton(stick1, 8);
	runCompressorButton->WhileHeld(new CompressorOveride());
	reverseWinchButton = new JoystickButton(stick1, 1);
	reverseWinchButton->WhenPressed(new ReverseWinch());
	compressorOverideButton = new JoystickButton(stick1, 3);
	compressorOverideButton->WhileHeld(new CompressorOveride());
	clawOpenButton = new JoystickButton(stick1, 5);
	clawOpenButton->WhileHeld(new ClawOpen());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("LedTurnOn", new LedTurnOn());
	SmartDashboard::PutData("Visiontrack", new Visiontrack());
	SmartDashboard::PutData("DeleteLog", new DeleteLog());
	SmartDashboard::PutData("LedTurnOff", new LedTurnOff());
	SmartDashboard::PutData("SetCameraForAuton", new SetCameraForAuton());
	SmartDashboard::PutData("SetCameraForTeleop", new SetCameraForTeleop());
	SmartDashboard::PutData("ActivatePhotonCannon", new ActivatePhotonCannon());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	SmartDashboard::PutData("Turn Left Relative", new TurnToAngle(true, 15));
	SmartDashboard::PutData("Turn Right Relative", new TurnToAngle(true, -15));
	SmartDashboard::PutData("Turn Left", new TurnToAngle(false, 15));
	SmartDashboard::PutData("Turn Right", new TurnToAngle(false, -15));
	SmartDashboard::PutBoolean("SpikeLEDVal", Robot::vision->ledSpike->Get());
	goToTruss = new JoystickButton(stick2, 4);
	goToGoal = new JoystickButton(stick2, 3);
	goToOnePoint = new JoystickButton(stick2, 2);
	goToFloor = new JoystickButton(stick2, 1);
	pass = new JoystickButton(stick2, 9);
	goToTruss->WhenPressed(new GoToAngle(false, Robot::trunnion->TRUSSANGLE));
	goToGoal->WhenPressed(new GoToAngle(false, Robot::trunnion->GOALANGLE));
	goToOnePoint->WhenPressed(new GoToAngle(false, Robot::trunnion->ONEPOINTANGLE));
	goToFloor->WhenPressed(new GoToAngle(false, Robot::trunnion->FLOORANGLE));
	pass->WhenPressed(new ClawSetWheel(1.0));
	pass->WhenReleased(new ClawSetWheel(0));
	drvLeftTrigger = new TriggerButton(stick1, 3, 0.5);
	drvRightTrigger = new TriggerButton(stick1, 3, -0.5);
	accLeftTrigger = new TriggerButton(stick2, 3, 0.5);
	accRightTrigger = new TriggerButton(stick2, 3, -0.5);
	accClawTrigger = new TriggerButton(stick2, 6, 0.5);
	accClawTrigger2 = new TriggerButton(stick2, 6, -0.5);
	drvLeftTrigger->WhenPressed(new FloorSnapPressed());
//	drvLeftTrigger->WhileHeld(new ClawSetWheel(-1.0));
	drvLeftTrigger->WhenReleased(new FloorSnapReleased());
	drvRightTrigger->WhenPressed(new ShiftDown());
	drvRightTrigger->WhenReleased(new ShiftUp());
	accLeftTrigger->WhenPressed(new Release());
	accRightTrigger->WhenPressed(new Shoot());
	accClawTrigger->WhenPressed(new ClawWheelToggle());
	accClawTrigger2->WhenPressed(new ClawSet());
//	SmartDashboard::PutData("GoToTrussAngle", new GoToAngle(false, Robot::trunnion->TRUSSANGLE));
//	SmartDashboard::PutData("GoToFloorAngle", new GoToAngle(false, Robot::trunnion->FLOORANGLE));
//	SmartDashboard::PutData("GoToGoalAngle", new GoToAngle(false, Robot::trunnion->GOALANGLE));
//	SmartDashboard::PutData("Autonomous Mode 1", new AutonomousCommandGroup(1));
//	SmartDashboard::PutData("Autonomous Mode 2", new AutonomousCommandGroup(2));
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
float OI::getScoopWheelStick() {
	return stick2->GetRawAxis(2);
}
