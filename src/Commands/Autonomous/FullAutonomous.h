#ifndef FULLAUTONOMOUS_H
#define FULLAUTONOMOUS_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

#include "MoveToDefense.h"
#include "CrossDefense.h"
#include "DriveToTargetAndShoot.h"

class FullAutonomous: public CommandGroup
{
	public:
	FullAutonomous(CrossDefense *cross, DriveToTargetAndShoot *shoot);
	FullAutonomous();

	private:

};


#endif
