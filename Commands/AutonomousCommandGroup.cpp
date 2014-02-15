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
	
	switch(position) {
	case 1: // 1 Shot
		AddSequential(new AutonWait(1));
		AddSequential(new GoToAngle(false, Robot::trunnion->GOALANGLE));
		if(!Robot::vision->GetGoalState()) {
			AddSequential(new AutonWait(1));
		}
		//if(!Robot::claw->GetClaw()) {
			AddParallel(new ClawSet());
		//}
		AddSequential(new AutonWait(0.25));
		AddSequential(new  Release());
		AddParallel(new ClawSet());
		AddParallel(new PullBack());
		AddSequential(new AutonDrive(0.5, 0.75));
		//AddSequential(new TurnToAngle(true, 180));
		break;
	case 2: // 2 SHOT
		AddSequential(new GoToAngle(false, Robot::trunnion->AUTON1ANGLE));
		if(!Robot::claw->GetClaw()) {
			AddSequential(new ClawSet());
		}
		AddSequential(new Release());
		AddSequential(new ShootPause());
		AddSequential(new ClawSet());	
		AddParallel(new GoToAngle(false, Robot::trunnion->FLOORANGLE));
		AddSequential(new PullBack());
		AddSequential(new ClawSetWheel());
//		AddSequential(new AutonWait(1.5));
		AddSequential(new AutonDrive(1.5, 0.5));
		AddSequential(new GoToAngle(false, Robot::trunnion->AUTON2ANGLE));
		AddSequential(new ClawSetWheel());
		AddSequential(new AutonWait(0.5));
		AddSequential(new Shoot());
		//AddSequential(new AutonDrive(0.5, 0.5));
		break;
	case 3:
		if(!Robot::vision->GetGoalState()) {
			AddSequential(new TurnToAngle(false, -15));
		}
		AddSequential(new Shoot());
		break;
	}
}
