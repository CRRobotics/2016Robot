#include "PorticullisAndShootAuton.h"
#include "../Autonomous/PorticullisAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"
#include "../AHRS/ResetDisplacement.h"

PorticullisAndShootAuton::PorticullisAndShootAuton(){
	AddSequential(new PorticullisAuton());
	AddSequential(new AutoDriveForward(-.5, 98));

	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveTurn(120));

	AddSequential(new ShiftHigh());
	AddSequential(new AutoDriveForward(.6, 75), 3);
	AddSequential(new AutoEjectBall());
}
