#ifndef FULLAUTONOMOUS_H
#define FULLAUTONOMOUS_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class FullAutonomous: public CommandGroup
{
	public:
	FullAutonomous(Robot::Defense defense, int defensePos);

	private:

};


#endif
