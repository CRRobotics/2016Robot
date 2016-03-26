#include "SimpleDriveAndShootRightAuton.h"
#include "../Autonomous/SimpleDriveAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"
#include "../AHRS/ResetDisplacement.h"

SimpleDriveAndShootRightAuton::SimpleDriveAndShootRightAuton(){
	AddSequential(new SimpleDriveAuton());
	AddSequential(new AutoDriveForward(.5, 98 - 20));

	AddSequential(new ShiftLow());
	AddSequential(new ResetDisplacement());
	AddSequential(new AutoDriveTurn(-60));

	AddSequential(new ShiftHigh());
	AddSequential(new AutoDriveForward(.6, 75), 3);
	AddSequential(new AutoEjectBall());
}
