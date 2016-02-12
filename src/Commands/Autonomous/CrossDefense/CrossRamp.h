#ifndef CROSSCHEVAL_H
#define CROSSCHEVAL_H

#include "Commands/Subsystem.h"
#include "../../../Robot.h"

class CrossCheval: public CommandGroup
{
	public:
		CrossCheval();

		virtual void Initialize();
		virtual void End();
		virtual void Interrupted();
	private:

};

#endif
