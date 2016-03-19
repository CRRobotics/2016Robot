#include "LowBarAndShootAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"
#include "../AHRS/ResetDisplacement.h"

LowBarAndShootAuton::LowBarAndShootAuton(){
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(1,24));
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN),3);
	AddSequential(new AutoDriveForward(1, 108));
	AddParallel(new ArmDriveToPos(Arm::Position::POS_START));
	AddSequential(new AutoDriveForward(1, 36 + .6631));
	AddSequential(new ResetDisplacement());
	AddSequential(new AutoDriveTurn(5));
	AddSequential(new AutoDriveForward(1, 60.219));
	//AddSequential(new ShiftHigh());
	AddSequential(new ResetDisplacement());
	AddSequential(new AutoDriveTurn(55));
	//AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(1, 135.0203));
}
