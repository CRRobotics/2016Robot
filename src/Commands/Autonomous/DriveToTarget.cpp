
#include "DriveToTarget.h"

#include "../Drive/AutoDriveForward.h"
#include "../Arm/ArmSetPos.h"

DriveToTarget::DriveToTarget(int defensePos): CommandGroup(){
	int currentAngle = Robot::drive->GetYaw() % 360;
	double robotDistFromBounds = BOUNDS_IN_TO_DEFENSES + IN_PER_DEFENSE * defensePos - IN_DEFENSE_OFFSET + Robot::drive->GetYDisplacement();
	double robotDistFromDefenseStart = Robot::drive->GetXDisplacement();
	double desiredAngle = 0;
}

void DriveToTarget::Initialize() {

}


void DriveToTarget::End(){

}

void DriveToTarget::Interrupted() {

}
