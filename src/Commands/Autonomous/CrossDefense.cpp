
#include "CrossDefense.h"

#include "../Drive/AutoDriveForward.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Arm/ArmDriveToPos.h"

#define PORT_IN_BEFORE_LIFT 12.0
#define PORT_IN_AFTER_LIFT 36.0
#define PORT_SPEED 1.0//TODO Determine

#define MOAT_IN 50.5
#define MOAT_SPEED 1.0//TODO Determine

#define RAMP_BEFORE_IN 12.0
#define RAMP_SPEED 1.0//TODO Determine
#define RAMP_CROSS_LIN 5
#define RAMP_CROSS_RIN 8
#define RAMP_CROSS_LSPEED 0.5//TODO Determine
#define RAMP_CROSS_RSPEED 1.0//TODO Determine
#define RAMP_AFTER_IN 29.2

#define WALL_IN 52.625
#define WALL_SPEED 1.0//TODO Determine

#define ROUGH_IN 50.0
#define ROUGH_SPEED 1.0//TODO Determine

#define DRAW_FOR_IN 12.0
#define DRAW_REV_IN -49
#define DRAW_OVER_IN 85.0
#define DRAW_FOR_SPEED 1.0//TODO Determine
#define DRAW_REV_SPEED 0.5//TODO Determine

#define LOW_IN 48.0
#define LOW_SPEED 1.0//TODO Determine

#define CHEVAL_SPEED 1.0//TODO Determine
#define CHEVAL_IN_BEFORE_LOWER 12.0
#define CHEVAL_IN_AFTER_LOWER 8.0
#define CHEVAL_IN_AT_TOP 12.0
#define CHEVAL_IN_AFTER_FALL 16.0

#define SALLY_SPEED 1.0//TODO Determine
#define SALLY_BEFORE_IN 12.0
#define SALLY_BACK_SPEED 0.5//TODO Determine
#define SALLY_BACK_IN -2.0
#define SALLY_CROSS_IN 38.0//TODO Determine

CrossDefense::CrossDefense(Robot::Defense def): CommandGroup(){
	switch (def)
	{
		case Robot::Defense::PORT://TODO FLIP ROBOT FOR THIS ONE
			AddSequential(new ArmDriveToPos(Arm::Position::POS_PORT));
			AddSequential(new AutoDriveForward(PORT_SPEED, PORT_IN_BEFORE_LIFT));
			AddSequential(new ArmDriveToPos(Arm::Position::POS_SCALE));//TODO Figure out how much to lift the Portcullis
			AddSequential(new AutoDriveForward(PORT_SPEED, PORT_IN_AFTER_LIFT));
		break;
		case Robot::Defense::CHEVAL://TODO FLIP ROBOT FOR THIS ONE
			AddParallel(new ArmDriveToPos(Arm::Position::POS_SALLY));
			AddSequential(new AutoDriveForward(CHEVAL_SPEED, CHEVAL_IN_BEFORE_LOWER));
			AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN));
			AddSequential(new AutoDriveForward(CHEVAL_SPEED, CHEVAL_IN_AFTER_LOWER));
			AddParallel(new ArmDriveToPos(Arm::Position::POS_PORT));
			AddSequential(new AutoDriveForward(0.3, CHEVAL_IN_AT_TOP));//Wait at top of cheval
			AddSequential(new AutoDriveForward(CHEVAL_SPEED,CHEVAL_IN_AFTER_FALL));
		break;
		case Robot::Defense::MOAT:
			AddSequential(new AutoDriveForward(MOAT_SPEED, MOAT_IN));
		break;
		case Robot::Defense::RAMP:
			AddSequential(new AutoDriveForward(RAMP_SPEED, RAMP_BEFORE_IN));
			AddSequential(new AutoDriveForward(RAMP_CROSS_LSPEED, RAMP_CROSS_RSPEED, RAMP_CROSS_LIN, RAMP_CROSS_RIN));
			AddSequential(new AutoDriveForward(RAMP_SPEED, RAMP_AFTER_IN));
		break;
		case Robot::Defense::DRAW://TODO FLIP ROBOT FOR THIS ONE
			AddSequential(new ArmDriveToPos(Arm::Position::POS_DRAW));
			AddSequential(new AutoDriveForward(DRAW_FOR_SPEED, DRAW_FOR_IN));
			AddSequential(new ArmDriveToPos(Arm::Position::LOWER));
			AddSequential(new AutoDriveForward(DRAW_REV_SPEED, DRAW_REV_IN));
			AddSequential(new ArmDriveToPos(Arm::Position::POS_PORT));//Figure out how much to lower the arm to drive over the drawbridge
			AddSequential(new AutoDriveForward(DRAW_FOR_SPEED, DRAW_OVER_IN));
		break;
		case Robot::Defense::SALLY://TODO FLIP ROBOT FOR THIS ONE
			AddSequential(new ArmDriveToPos(Arm::Position::POS_SALLY));
			AddSequential(new AutoDriveForward(SALLY_SPEED, SALLY_BEFORE_IN));
			AddSequential(new ArmDriveToPos(Arm::Position::LOWER));
			AddParallel(new ArmDriveToPos(Arm::Position::LOWER));
			AddSequential(new AutoDriveForward(SALLY_BACK_SPEED, SALLY_BACK_IN));
			AddSequential(new AutoDriveTurn(0));
			AddSequential(new AutoDriveForward(SALLY_SPEED, SALLY_CROSS_IN));
		break;
		case Robot::Defense::WALL:
			AddSequential(new AutoDriveForward(WALL_SPEED, WALL_IN));
		break;
		case Robot::Defense::ROUGH:
			AddSequential(new AutoDriveForward(ROUGH_SPEED, ROUGH_IN));
		break;
		case Robot::Defense::LOW://TODO FLIP ROBOT FOR THIS ONE
			AddSequential(new AutoDriveForward(LOW_SPEED, LOW_IN));
		break;

	}
	SmartDashboard::PutString("auto_stage", "cross defense");
}

void CrossDefense::Initialize() {
	SmartDashboard::PutString("auto_stage_overall", "cross defense");
}


void CrossDefense::End() {

}

void CrossDefense::Interrupted() {

}
