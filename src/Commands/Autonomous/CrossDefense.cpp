
#include "CrossDefense.h"

#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"

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
			//Figure out how we plan to do this.
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
			//Wait for arm to move down
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
