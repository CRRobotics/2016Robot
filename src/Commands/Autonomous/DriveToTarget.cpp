
#include "DriveToTarget.h"

#include "../Drive/AutoDriveForward.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Arm/ArmDriveToPos.h"

DriveToTarget::DriveToTarget(int defensePos, double targetPositionX, double targetPositionY): CommandGroup(){
	double currentRobotAngle = Robot::drive->GetYaw();
	double robotX = defensePos * SQ_PER_DEFENSE - DEFENSE_OFFSET + Robot::drive->GetXDisplacement() * METERS_TO_SQ;
	double robotY = DEFENSE_START_Y + Robot::drive->GetYDisplacement() * METERS_TO_SQ;
	double deltaX = targetPositionX - robotX;
	double deltaY = targetPositionY - robotY;
	double desiredAngle = -atan2(deltaX, deltaY) * 180 / M_PI;
	AddSequential(new AutoDriveTurn(1.0, desiredAngle));
}

int DriveToTarget::mod(int a, int n){
	return a - floor(a/n) * n;
}

void DriveToTarget::Initialize() {

}


void DriveToTarget::End(){

}

void DriveToTarget::Interrupted() {

}
