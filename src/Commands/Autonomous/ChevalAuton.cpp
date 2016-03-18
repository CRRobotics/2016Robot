#include "ChevalAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"


ChevalAuton::ChevalAuton(){
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(-1,24));

	AddSequential(new AutoDriveForward(-.5,8),2);
	AddParallel(new ArmDriveToPos(Arm::Position::POS_DOWN), 2);
	AddSequential(new AutoDriveForward(1, 9));
	AddParallel(new ArmDriveToPos(Arm::Position::POS_START));
	AddSequential(new AutoDriveForward(-1, 120));
}
