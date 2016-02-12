#ifndef CROSSPORT_H
#define CROSSPORT_H

#include "Commands/Subsystem.h"
#include "../../../Robot.h"

//TODO Determine constants
#define INCHESBEFORELIFT 20
#define INCHESAFTERLIFT 20

class CrossPort: public CommandGroup
{
	public:
		CrossPort();

		virtual void Initialize();
		virtual void End();
		virtual void Interrupted();
	private:

};

#endif
