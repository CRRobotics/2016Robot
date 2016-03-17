#include "LowBarAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"

LowBarAuton::LowBarAuton(){
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(1,24));
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN),3);
	AddSequential(new AutoDriveForward(1, 213));
	AddSequential(new AutoDriveTurn(60));
	AddSequential(new AutoDriveForward(1,150));
	AddSequential(new AutoEjectBall());
}