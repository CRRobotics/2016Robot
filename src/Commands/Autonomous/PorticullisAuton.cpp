#include "PorticullisAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"

PorticullisAuton::PorticullisAuton(){
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(-.25, 42));
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN), 1.8);
	AddSequential(new AutoDriveForward(-.25, 10));
	AddParallel(new ArmDriveToPos(Arm::Position::POS_PORT), 1.8);
	AddSequential(new AutoDriveForward(-.75, 98));
	AddSequential(new ShiftHigh());
}
