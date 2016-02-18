#include "FullAutonomous.h"
#include "MoveToDefense.h"
#include "CrossDefense.h"
#include "DriveToTargetAndShoot.h"

#define TARGET_X 262.2154
#define TARGET_Y 550.6462

FullAutonomous::FullAutonomous(Robot::Defense defense, int defenseNum): CommandGroup(){
	AddSequential(new MoveToDefense());
	AddSequential(new CrossDefense(defense));
	AddSequential(new DriveToTargetAndShoot(defenseNum, TARGET_X, TARGET_Y));
}
