
#include "DriveToTargetAndShoot.h"

#include "../Drive/AutoDriveForward.h"
#include "../Drive/AutoDriveTurn.h"
#include "../Arm/ArmDriveToPos.h"
#include "../Acquisition/AutoEjectBall.h"
#include "DriveToAndCrossLowBar.h"

DriveToTargetAndShoot::DriveToTargetAndShoot(int defensePos, double targetPositionX, double targetPositionY): CommandGroup(){
	m_defensePos = defensePos;
	m_targetX = targetPositionX;
	m_targetY = targetPositionY;
}


void DriveToTargetAndShoot::Initialize() {
	double robotX = m_defensePos * SQ_PER_DEFENSE - DEFENSE_OFFSET + Robot::drive->GetXDisplacement() * METERS_TO_SQ;
		double robotY = DEFENSE_START_Y + Robot::drive->GetYDisplacement() * METERS_TO_SQ;
		double deltaX = m_targetX - robotX;
		double deltaY = m_targetY - robotY;
		double desiredAngle = -atan2(deltaX, deltaY) * 180 / M_PI;
		double distance = sqrt(deltaX * deltaX + deltaY * deltaY);
		AddSequential(new AutoDriveTurn(desiredAngle));
		AddSequential(new AutoDriveForward(1.0, distance / 2));
		double targetXToTowerX = TOWER_CENTER_X - m_targetX;
		double targetYToTowerY = TOWER_CENTER_Y - m_targetY;
		double targetToTowerAngle = -atan2(targetXToTowerX, targetYToTowerY) * 180 / M_PI;
		AddSequential(new AutoDriveTurn(targetToTowerAngle));
		double targetToTowerDistance = sqrt(targetXToTowerX * targetXToTowerX + targetYToTowerY * targetYToTowerY);
		double targetToGoalDistance = targetToTowerDistance - TOWER_CENTER_TO_GOAL;
		AddSequential(new AutoDriveForward(1.0, targetToGoalDistance / 2));
		AddSequential(new AutoEjectBall());
		AddSequential(new AutoDriveForward(1.0, -targetToGoalDistance / 2));
		AddSequential(new DriveToAndCrossLowBar(m_targetX, m_targetY));
	SmartDashboard::PutString("auto_stage_overall", "Drive to target");
}


void DriveToTargetAndShoot::End(){

}

void DriveToTargetAndShoot::Interrupted() {

}
