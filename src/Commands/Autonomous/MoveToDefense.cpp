
#include "MoveToDefense.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/ShiftLow.h"

MoveToDefense::MoveToDefense(): CommandGroup()
{
	//AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN));//Arm is down by default at the beginning of the game
	AddSequential(new AutoDriveForward(1.0, INCHESTODEFENSE));
}

void MoveToDefense::Initialize() {
	SmartDashboard::PutString("auto_stage_overall", "Move To Defense");
}



void MoveToDefense::End() {
	Robot::drive->ahrs->ZeroYaw();
}

void MoveToDefense::Interrupted() {

}
