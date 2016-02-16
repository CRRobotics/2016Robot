#ifndef CROSSDEFENSE_H
#define CROSSDEFENSE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"



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
