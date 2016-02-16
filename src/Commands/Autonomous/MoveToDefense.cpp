
#include "MoveToDefense.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/ShiftHigh.h"

MoveToDefense::MoveToDefense(): CommandGroup()
{

	AddSequential(new ShiftHigh());
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN));//Arm is down by default at the beginning of the game
	AddSequential(new AutoDriveForward(1.0, INCHESTODEFENSE));
}

void MoveToDefense::Initialize() {

}



void MoveToDefense::End() {
	Robot::drive->ResetNavX();
}

void MoveToDefense::Interrupted() {

}
