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
	AddSequential(new AutonWait(1));
	AddSequential(new GoToAngle(false, Robot::trunnion->GOALANGLE));
	
	switch(position) {
	case 1: // 1 Shot
		if(!Robot::vision->GetGoalState()) {
			AddSequential(new AutonWait(1));
		}
		//if(!Robot::claw->GetClaw()) {
			AddParallel(new ClawSet());
		//}
		AddSequential(new  Release());
		AddParallel(new ClawSet());
		AddParallel(new PullBack());
		AddParallel(new AutonDrive(1000, 0.25));
		break;
	case 2: // 2 SHOT
		if(Robot::vision->GetGoalState()) {
			AddSequential(new TurnToAngle(true, 30));
		} else {
			AddSequential(new TurnToAngle(true, -30));
		}
		AddSequential(new Shoot());
		AddParallel(new GoToAngle(false, Robot::trunnion->FLOORANGLE));
		if(Robot::vision->GetGoalState()) {
			AddSequential(new TurnToAngle(true, -30));
		} else {
			AddSequential(new TurnToAngle(true, 30));
		}
		//if(!Robot::claw->GetWheel()) {
			AddParallel(new ClawSetWheel());
		//}
		AddSequential(new AutonDrive(1000, 0.25));
		AddParallel(new ClawSetWheel());
		AddParallel(new GoToAngle(false, Robot::trunnion->GOALANGLE));
		AddSequential(new AutonDrive(-1000, -0.25));
		if(Robot::vision->GetGoalState()) {
			AddSequential(new TurnToAngle(true, -30));
		} else {
			AddSequential(new TurnToAngle(true, 30));
		}
		AddSequential(new Shoot());
		AddSequential(new AutonDrive(1000, 0.25));
		break;
	}
}
