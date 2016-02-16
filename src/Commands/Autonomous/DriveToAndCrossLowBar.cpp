#include "DriveToAndCrossLowBar.h"

#include "../Drive/AutoDriveForward.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Acquisition/AutoEjectBall.h"
#include "CrossDefense.h"


DriveToAndCrossLowBar::DriveToAndCrossLowBar(double robotX, double robotY){
//	double robotToLowX = LOW_BAR_X - robotX;
//	double robotToLowY = LOW_BAR_FORWARD_Y - robotY;
//	double desiredAngle = -atan2(robotToLowX, robotToLowY);
//	AddSequential(new AutoDriveTurn(desiredAngle));
//	double distanceToLowX = sqrt(robotToLowX * robotToLowX + robotToLowY * robotToLowY);
//	AddSequential(new AutoDriveForward(1.0, distanceToLowX));
//	AddSequential(new AutoDriveTurn(-180));
//	AddSequential(new AutoDriveForward(1.0, LOW_BAR_FORWARD_TO_START));
//	AddSequential(new CrossDefense(Robot::Defense::LOW));
//	AddSequential(new AutoDriveForward(1.0, DIST_AFTER_LOW_BAR));
	CommandGroup* a = new CommandGroup();
	a->AddSequential(new AutoDriveForward(1,1));
}

void DriveToAndCrossLowBar::Initialize(){

}

void DriveToAndCrossLowBar::Interrupted(){

}

void DriveToAndCrossLowBar::End(){

}
