#include "CrossPort.h"

#include "../../Drive/AutoDriveForward.h"
#include "../../Arm/ArmDriveToPos.h"

CrossPort::CrossPort(): CommandGroup()
{
	AddSequential(new ArmDriveToPos(Arm::Position::POS_PORT));
	AddSequential(new AutoDriveForward(1.0, INCHESBEFORELIFT));
	AddSequential(new ArmDriveToPos(Arm::Position::POS_SCALE));//TODO Figure out how much to lift the Portcullis
	AddSequential(new AutoDriveForward(1.0, INCHESAFTERLIFT));
}

void CrossPort::Initialize() {

}


void CrossPort::End() {

}

void CrossPort::Interrupted() {

}
