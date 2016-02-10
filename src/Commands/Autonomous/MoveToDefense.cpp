
#include "MoveToDefense.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmSetPos.h"

MoveToDefense::MoveToDefense(): CommandGroup()
{
	AddSequential(new ArmSetPos(Arm::Position::POS_DOWN));//Arm is down by default at the beginning of the game
	AddSequential(new AutoDriveForward(1.0, INCHESTODEFENSE));
}

void MoveToDefense::Initialize() {

}



void MoveToDefense::End() {
	Robot::drive->ahrs->ResetDisplacement();
	Robot::drive->ahrs->ZeroYaw();
}

void MoveToDefense::Interrupted() {

}
