#ifndef DRIVETOTARGETANDSHOOT_H
#define DRIVETOTARGETANDSHOOT_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

//TODO Determine these constants
//1 Sq = 1/2 in.
#define SQ_PER_DEFENSE 100.75 //Width of one platform and one barrier in sq
#define DEFENSE_OFFSET SQ_PER_DEFENSE/2
#define DEFENSE_START_Y 11//TODO determine
#define METERS_TO_SQ 39.3701 * 2

#define TOWER_CENTER_X 319
#define TOWER_CENTER_Y 649
#define TOWER_CENTER_TO_GOAL  sqrt(3) * 12 * 2 * 1.35

class DriveToTargetAndShoot: public CommandGroup
{
	public:
	DriveToTargetAndShoot(int defensePos, double targetX, double targetY);

	virtual void Initialize();
	virtual void End();
	virtual void Interrupted();

	private:
	int m_defensePos;
	double m_targetX;
	double m_targetY;

};


#endif
