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
	AddSequential(new AutoDriveForward(.75, 144));
	AddSequential(new ResetDisplacement());
	AddSequential(new AutoDriveTurn(5));
	AddSequential(new AutoDriveForward(.75, 60.219));
	AddSequential(new AutoDriveTurn(55));
	AddSequential(new AutoDriveForward(.75, 135.0203));
}
