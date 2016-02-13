#ifndef DRIVETOANDCROSSLOW_H
#define DRIVETOANDCROSSLOW_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"
#include "DriveToTargetAndShoot.h"

#define LOW_BAR_X (SQ_PER_DEFENSE / 2)
#define LOW_BAR_FORWARD_Y 100//TODO Determine
#define LOW_BAR_FORWARD_TO_START 10//TODO Determine
#define DIST_AFTER_LOW_BAR 10//TODO Determine

//1 Sq = 1/2 in.

class DriveToAndCrossLowBar: CommandGroup
{
	public:
	DriveToAndCrossLowBar(double robotX, double robotY);

	virtual void Initialize();
	virtual void End();
	virtual void Interrupted();

	private:


};


#endif
