#ifndef CROSSDEFENSE_H
#define CROSSDEFENSE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

//TODO Determine all of these constants
#define PORT_IN_BEFORE_LIFT 20.0
#define PORT_IN_AFTER_LIFT 20.0
#define PORT_SPEED 1.0

#define MOAT_IN 40.0
#define MOAT_SPEED 1.0

#define RAMP_BEFORE_IN 40.0
#define RAMP_SPEED 1.0
#define RAMP_CROSS_IN 10
#define RAMP_CROSS_LSPEED 0.5
#define RAMP_CROSS_RSPEED 1.0
#define RAMP_AFTER_IN 10.0

#define WALL_IN 40.0
#define WALL_SPEED 1.0

#define ROUGH_IN 40.0
#define ROUGH_SPEED 1.0

#define DRAW_FOR_IN 10.0
#define DRAW_REV_IN 5.0
#define DRAW_OVER_IN 35.0
#define DRAW_ARM_LOWER Robot::arm->GetPotValueForPos(Arm::Position::POS_DRAW) - 5.0
#define DRAW_FOR_SPEED 1.0
#define DRAW_REV_SPEED 0.5

#define LOW_IN_BEFORE_LOWER 10.0
#define LOW_IN_AFTER_LOWER 30.0
#define LOW_SPEED 1.0

class CrossDefense: public CommandGroup
{
	public:
		CrossDefense(Robot::Defense def);

		virtual void Initialize();
		virtual void End();
		virtual void Interrupted();
	private:

};

#endif
