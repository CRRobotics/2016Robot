
#include "CrossDefense.h"

#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"

//TODO Determine all of these constants
#define PORT_IN_BEFORE_LIFT 20.0
#define PORT_IN_AFTER_LIFT 20.0
#define PORT_SPEED 1.0

#define MOAT_IN 40.0
#define MOAT_SPEED 1.0

#define RAMP_BEFORE_IN 40.0
#define RAMP_SPEED 1.0
#define RAMP_CROSS_IN 10
#define RAMP_CROSS_LSPEED 0.5
#define RAMP_CROSS_RSPEED 1.0
#define RAMP_AFTER_IN 10.0

#define WALL_IN 40.0
#define WALL_SPEED 1.0

#define ROUGH_IN 40.0
#define ROUGH_SPEED 1.0

#define DRAW_FOR_IN 10.0
#define DRAW_REV_IN 5.0
#define DRAW_OVER_IN 35.0
#define DRAW_ARM_LOWER Robot::arm->GetPotValueForPos(Arm::Position::POS_DRAW) - 5.0
#define DRAW_FOR_SPEED 1.0
#define DRAW_REV_SPEED 0.5

#define LOW_IN_BEFORE_LOWER 10.0
#define LOW_IN_AFTER_LOWER 30.0
#define LOW_SPEED 1.0

#define CHEVAL_SPEED 1.0
#define CHEVAL_IN_BEFORE_LOWER 1.0
#define CHEVAL_IN_AFTER_LOWER 1.0
#define CHEVAL_IN_AT_TOP 1.0
#define CHEVAL_IN_AFTER_FALL 1.0

CrossDefense::CrossDefense(Robot::Defense def): CommandGroup(){
	switch (def)
	{
		case Robot::Defense::PORT:
			AddSequential(new ArmDriveToPos(Arm::Position::POS_PORT));
			AddSequential(new AutoDriveForward(PORT_SPEED, PORT_IN_BEFORE_LIFT));
			AddSequential(new ArmDriveToPos(Arm::Position::POS_SCALE));//TODO Figure out how much to lift the Portcullis
			AddSequential(new AutoDriveForward(PORT_SPEED, PORT_IN_AFTER_LIFT));
		break;
		case Robot::Defense::CHEVAL:
			AddParallel(new ArmDriveToPos(Arm::Position::POS_SALLY));
			AddSequential(new AutoDriveForward(CHEVAL_SPEED, CHEVAL_IN_BEFORE_LOWER));
			AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN));
			AddSequential(new AutoDriveForward(CHEVAL_SPEED, CHEVAL_IN_AFTER_LOWER));
			AddSequential(new AutoDriveForward(0.3, CHEVAL_IN_AT_TOP));//Wait at top of cheval
			AddSequential(new AutoDriveForward(CHEVAL_SPEED,CHEVAL_IN_AFTER_FALL));
		break;
		case Robot::Defense::MOAT:
			AddSequential(new AutoDriveForward(MOAT_SPEED, MOAT_IN));
		break;
		case Robot::Defense::RAMP:
//			AddSequential(new AutoDriveForward(RAMP_SPEED, RAMP_IN));
		break;
		case Robot::Defense::DRAW:
			AddSequential(new ArmDriveToPos(Arm::Position::POS_DRAW));
			AddSequential(new AutoDriveForward(DRAW_FOR_SPEED, DRAW_FOR_IN));
			AddSequential(new ArmDriveToPos(Arm::Position::POS_DRAW_LOWER));
			AddSequential(new AutoDriveForward(DRAW_REV_SPEED, DRAW_REV_IN));
			AddSequential(new ArmDriveToPos(Arm::Position::POS_PORT));//Figure out how much to lower the arm to drive over the drawbridge
			AddSequential(new AutoDriveForward(DRAW_FOR_SPEED, DRAW_OVER_IN));
		break;
		case Robot::Defense::SALLY:

		break;
		case Robot::Defense::WALL:
			AddSequential(new AutoDriveForward(WALL_SPEED, WALL_IN));
		break;
		case Robot::Defense::ROUGH:
			AddSequential(new AutoDriveForward(ROUGH_SPEED, ROUGH_IN));
		break;
		case Robot::Defense::LOW:
			AddSequential(new ArmDriveToPos(Arm::Position::POS_PORT));//TODO Figure out how high to raise the arm before crossing the low bar
			AddSequential(new AutoDriveForward(LOW_SPEED, LOW_IN_BEFORE_LOWER));
			AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN));
			AddSequential(new AutoDriveForward(LOW_SPEED, LOW_IN_AFTER_LOWER));
		break;
		default:
			return;//Come up with default case
	}
}

void CrossDefense::Initialize() {

}


void CrossDefense::End() {

}

void CrossDefense::Interrupted() {

}
