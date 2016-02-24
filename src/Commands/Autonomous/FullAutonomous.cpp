#include "FullAutonomous.h"
#include "../Drive/ShiftLow.h"

FullAutonomous::FullAutonomous(CrossDefense* cross, DriveToTargetAndShoot* shoot): CommandGroup(){
//	AddSequential(new MoveToDefense());
//	AddSequential(new CrossDefense(defense));
//	AddSequential(new DriveToTargetAndShoot(defenseNum, TARGET_X, TARGET_Y));
	AddSequential(new MoveToDefense());
	AddSequential(cross);
	AddSequential(shoot);
}


FullAutonomous::FullAutonomous(){
	AddSequential(new ShiftLow());
	AddSequential(new MoveToDefense());
	AddSequential(new CrossDefense(Robot::Defense::LOW));
	AddSequential(new DriveToTargetAndShoot(4, 262.2154, 550.6462));
}
