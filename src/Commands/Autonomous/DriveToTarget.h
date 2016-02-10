#ifndef DRIVETOTARGET_H
#define DRIVETOTARGET_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

//TODO Determine these constants
#define BOUNDS_IN_TO_DEFENSES 10
#define IN_PER_DEFENSE 10
#define IN_DEFENSE_OFFSET IN_PER_DEFENSE/2

#define BOUNDS_IN_TO_TARGET 100
#define START_TO_TARGET 100


class DriveToTarget: CommandGroup
{
	public:
	DriveToTarget(int defensePos);

	virtual void Initialize();
	virtual void End();
	virtual void Interrupted();

	private:

};


#endif
