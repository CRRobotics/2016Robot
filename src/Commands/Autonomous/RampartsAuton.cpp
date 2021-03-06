#include "RampartsAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"

RampartsAuton::RampartsAuton(){
	AddParallel(new ArmDriveToPos(Arm::Position::POS_SALLY));
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(1,24));
	AddSequential(new AutoDriveForward(.75,120));
	AddSequential(new ShiftHigh());
}
