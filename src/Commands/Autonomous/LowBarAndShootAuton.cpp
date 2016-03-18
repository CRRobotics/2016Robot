#include "LowBarAndShootAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Acquisition/AutoEjectBall.h"
#include "../AHRS/ResetDisplacement.h"

LowBarAndShootAuton::LowBarAndShootAuton(){
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(.75,24));
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN),3);
	AddSequential(new AutoDriveForward(.75, 213));
	AddSequential(new ResetDisplacement());
	AddSequential(new AutoDriveTurn(60));
	AddSequential(new AutoDriveForward(.5,150));
	AddSequential(new AutoEjectBall());
}
