// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.



#include "AutonomousCommandGroup.h"
#include "Visiontrack.h"
#include "GoToAngle.h"
#include "AutonWait.h"
#include "Shoot.h"
#include "AutonDrive.h"
#include "TurnToAngle.h"
#include "ClawSetWheel.h"
#include "ClawSet.h"
#include "Release.h"
#include "Pullback.h"
#include "ShootPause.h"
#include "PullBack.h"
#include "ClawSet.h"
#include "Turn.h"
#include "ClawWheelToggle.h"
#include "AutonWheelSet.h"
#include "LedTurnOn.h"
#include "LedTurnOff.h"
#include "SetCameraForAuton.h"
#include "SetClawLedandRing.h"

AutonomousCommandGroup::AutonomousCommandGroup(int position) {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential(new LedTurnOn());
	AddSequential(new SetClawLedandRing(true));
	AddSequential(new SetCameraForAuton());
	
	switch(position) {
	case 0:
		AddSequential(new LedTurnOff());
		break;
	case 1: // 1 Shot
		AddParallel(new GoToAngle(false, 2.501));
		AddSequential(new AutonWait(2.0));
		AddSequential(new Visiontrack());
		//3.4
		//2.8
		if(Robot::vision->GetGoalState() == false) {
			AddSequential(new AutonWait(2.75));
		}
		AddSequential(new ClawSet());
		AddSequential(new AutonWait(0.25));
		AddSequential(new  Release());
		AddSequential(new ClawSet());
		AddParallel(new PullBack());
		AddSequential(new AutonDrive(0.5, 0.75));
//		SmartDashboard::PutBoolean("AutonGoalState", Robot::vision->GetGoalState());
		break;
	case 2: // 2 SHOT
		AddSequential(new GoToAngle(false, Robot::trunnion->AUTON1ANGLE));
		AddSequential(new ClawSet());
		AddSequential(new AutonWait(0.75));
		AddSequential(new Release());
		AddSequential(new ShootPause());
		AddSequential(new ClawSet());
		AddParallel(new GoToAngle(false, Robot::trunnion->FLOORANGLE));
		AddParallel(new PullBack());
		AddParallel(new AutonWheelSet(-1));
		AddSequential(new AutonWait(0.25));
		AddSequential(new AutonDrive(2, 0.4));
		AddSequential(new GoToAngle(false, Robot::trunnion->AUTON2ANGLE + 0.1));
		AddParallel(new AutonWheelSet(0));
		AddSequential(new AutonWait(0.25));
		if(!Robot::claw->GetClaw()) {
			AddSequential(new ClawSet());
		}
		AddSequential(new AutonWait(0.75));
		AddSequential(new Release());
		AddSequential(new ShootPause());
		AddSequential(new ClawSet());
		AddParallel(new PullBack());
		AddSequential(new AutonDrive(0.4, 1.0));
		break;
	case 3: //Drive Foreward for zone points
		AddSequential(new AutonDrive(2, 0.8));
		break;
	case 4: //Vision Track 2 Shot
		AddSequential(new AutonWait(1));
		AddSequential(new Visiontrack());
		if(Robot::vision->GetGoalState() == false) {
			AddSequential(new GoToAngle(false, Robot::trunnion->CROSSSHOT));
			AddSequential(new Turn(-0.5, 0.25));
		} else {
			AddSequential(new GoToAngle(false, Robot::trunnion->AUTON1ANGLE));
		}
		if(!Robot::claw->GetClaw()) {
			AddSequential(new ClawSet());
		}
		AddSequential(new Release());
		AddSequential(new ShootPause());
		AddSequential(new ClawSet());
		if(Robot::vision->GetGoalState() == false) {
			AddSequential(new Turn(0.5, 0.25));
		}
		AddParallel(new GoToAngle(false, Robot::trunnion->FLOORANGLE));
		AddSequential(new PullBack());
		AddSequential(new ClawSetWheel(1));
		AddSequential(new AutonWait(1.0));
		AddSequential(new AutonDrive(2, 0.4));
		AddSequential(new GoToAngle(false, Robot::trunnion->AUTON2ANGLE));
		//AddSequential(new Visiontrack());
		if(Robot::vision->GetGoalState() == true) {
			AddSequential(new GoToAngle(false, Robot::trunnion->CROSSSHOT));
			AddSequential(new Turn(0.5, 0.25));
		} else {
			AddSequential(new GoToAngle(false, Robot::trunnion->AUTON1ANGLE));
		}
		AddSequential(new ClawSetWheel(0));
		AddSequential(new AutonWait(0.5));
		AddSequential(new Shoot());
		if(Robot::vision->GetGoalState() == true) {
			AddSequential(new Turn(-0.5, 0.25));
		}
		AddSequential(new AutonDrive(0.5, 0.5));
		break;
	}
}
