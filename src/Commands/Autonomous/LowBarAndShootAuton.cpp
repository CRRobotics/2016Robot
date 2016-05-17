#include "LowBarAndShootAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"
#include "../AHRS/ResetDisplacement.h"

LowBarAndShootAuton::LowBarAndShootAuton(){
	AddSequential(new ResetDisplacement());
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(1,24));

	AddSequential(new ShiftHigh());
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN), 2);
	AddSequential(new AutoDriveForward(.75, 108 - 9 + 16 - 2 - 6 - 7 + 4 + 15));

	AddSequential(new ShiftLow());
	AddSequential(new ArmDriveToPos(Arm::Position::POS_START), 2);
	//AddSequential(new AutoDriveForward(1, 36 + .6631));
	//AddSequential(new ResetDisplacement());
	AddSequential(new AutoDriveTurn(10));

	AddSequential(new ShiftHigh());
	AddSequential(new AutoDriveForward(.75, 60.219 - 2 - 6));
	//AddSequential(new ResetDisplacement());

	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveTurn(60));
	//AddSequential(new ShiftLow());

	AddSequential(new ShiftHigh());
	AddSequential(new AutoDriveForward(.5, 135.0203), 2.5);
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveTurn(60), 1);
	AddSequential(new AutoEjectBall(), 3);
	AddSequential(new ShiftHigh());
}
