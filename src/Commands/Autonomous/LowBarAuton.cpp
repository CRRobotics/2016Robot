#include "LowBarAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"

LowBarAuton::LowBarAuton(){
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(1,24));
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN), 1.8);
	AddSequential(new AutoDriveForward(1, 124));
	AddSequential(new AutoDriveForward(-1, 96));
	AddSequential(new ShiftHigh());
}
