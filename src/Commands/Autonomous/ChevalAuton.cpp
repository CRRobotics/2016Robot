#include "ChevalAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"


ChevalAuton::ChevalAuton(){
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(-.75,48));
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN), 2);
	AddSequential(new AutoDriveForward(.5, 2));
	AddParallel(new ArmDriveToPos(Arm::Position::POS_START));
	AddSequential(new AutoDriveForward(-1, 120));
}
