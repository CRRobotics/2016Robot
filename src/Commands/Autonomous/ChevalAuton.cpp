#include "ChevalAuton.h"
#include "../Drive/ShiftLow.h"
#include "../Drive/ShiftHigh.h"
#include "../Drive/AutoDriveForward.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Arm/ArmDriveToPos.h"


ChevalAuton::ChevalAuton(){
	AddSequential(new ShiftLow());
	AddSequential(new AutoDriveForward(-.5,48));
	AddSequential(new ArmDriveToPos(Arm::Position::POS_DOWN), 2);
	//AddSequential(new AutoDriveForward(.25, 2));
	AddSequential(new AutoDriveForward(-.5, 6));
	AddParallel(new ArmDriveToPos(Arm::Position::POS_START));
	AddSequential(new AutoDriveForward(-1, 64));
	AddSequential(new ShiftHigh());
}

void ChevalAuton::End()
{
	Robot::oi->m_drvTurnShootL->WhenPressed(new AutoDriveTurn(-120));
	Robot::oi->m_drvTurnShootR->WhenPressed(new AutoDriveTurn(120));
}

void ChevalAuton::Interrupted()
{
	End();
}
