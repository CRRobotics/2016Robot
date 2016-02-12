#ifndef DRIVETOTARGET_H
#define DRIVETOTARGET_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

//TODO Determine these constants
//1 Sq = 1/2 in.
#define SQ_PER_DEFENSE 100
#define DEFENSE_OFFSET SQ_PER_DEFENSE/2
#define DEFENSE_START_Y 100.75 //Width of one platform and one barrier in sq
#define METERS_TO_SQ 39.3701 * 2

class DriveToTarget: CommandGroup
{
	public:
	DriveToTarget(int defensePos, double targetX, double targetY);

	virtual void Initialize();
	virtual void End();
	virtual void Interrupted();

	private:

	int mod(int a, int n);

};


#endif
