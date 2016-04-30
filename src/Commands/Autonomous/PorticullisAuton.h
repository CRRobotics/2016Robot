#ifndef PorticullisAuton_H
#define PorticullisAuton_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

#include "MoveToDefense.h"
#include "CrossDefense.h"
#include "DriveToTargetAndShoot.h"

class PorticullisAuton: public CommandGroup
{
	public:
	PorticullisAuton();
	virtual void End();
	virtual void Interrupted();

	private:

};


#endif
