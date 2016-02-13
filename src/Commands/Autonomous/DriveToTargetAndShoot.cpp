
#include "DriveToTargetAndShoot.h"

#include "../Drive/AutoDriveForward.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Acquisition/AutoEjectBall.h"

DriveToTargetAndShoot::DriveToTargetAndShoot(int defensePos, double targetPositionX, double targetPositionY): CommandGroup(){
	double robotX = defensePos * SQ_PER_DEFENSE - DEFENSE_OFFSET + Robot::drive->GetXDisplacement() * METERS_TO_SQ;
	double robotY = DEFENSE_START_Y + Robot::drive->GetYDisplacement() * METERS_TO_SQ;
	double deltaX = targetPositionX - robotX;
	double deltaY = targetPositionY - robotY;
	double desiredAngle = -atan2(deltaX, deltaY) * 180 / M_PI;
	double distance = sqrt(deltaX * deltaX + deltaY * deltaY);
	AddSequential(new AutoDriveTurn(desiredAngle));
	AddSequential(new AutoDriveForward(1.0, distance / 2));
	double targetXToTowerX = TOWER_CENTER_X - targetPositionX;
	double targetYToTowerY = TOWER_CENTER_Y - targetPositionY;
	double targetToTowerAngle = -atan2(targetXToTowerX, targetYToTowerY);
	AddSequential(new AutoDriveTurn(targetToTowerAngle));
	double targetToTowerDistance = sqrt(targetXToTowerX * targetXToTowerX + targetYToTowerY * targetYToTowerY);
	double targetToGoalDistance = targetToTowerDistance - TOWER_CENTER_TO_GOAL;
	AddSequential(new AutoDriveForward(1.0, targetToGoalDistance / 2));
	AddSequential(new AutoEjectBall());
}

int DriveToTargetAndShoot::mod(int a, int n){
	return a - floor(a/n) * n;
}

void DriveToTargetAndShoot::Initialize() {

}


void DriveToTargetAndShoot::End(){

}

void DriveToTargetAndShoot::Interrupted() {

}
