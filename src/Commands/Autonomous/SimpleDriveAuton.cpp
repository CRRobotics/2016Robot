#include "SimpleDriveAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"
#include "../AHRS/ResetDisplacement.h"

SimpleDriveAuton::SimpleDriveAuton(){
	AddSequential(new ResetDisplacement());
	AddParallel(new ArmDriveToPos(Arm::Position::POS_SALLY));
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(1, 24));
	AddSequential(new AutoDriveForward(.75, 108));
	AddSequential(new AutoDriveTurn(0));
	AddSequential(new AutoDriveForward(1, 18));
	AddSequential(new ShiftHigh());
}
