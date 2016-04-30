#ifndef ChevalAuton_H
#define ChevalAuton_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class ChevalAuton: public CommandGroup
{
	public:
	ChevalAuton();

	virtual void End();
	virtual void Interrupted();

	private:

};


#endif
