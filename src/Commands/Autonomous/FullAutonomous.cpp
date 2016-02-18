#include "FullAutonomous.h"


FullAutonomous::FullAutonomous(CrossDefense* cross, DriveToTargetAndShoot* shoot): CommandGroup(){
//	AddSequential(new MoveToDefense());
//	AddSequential(new CrossDefense(defense));
//	AddSequential(new DriveToTargetAndShoot(defenseNum, TARGET_X, TARGET_Y));
	AddSequential(new MoveToDefense());
	AddSequential(cross);
	AddSequential(shoot);
}
