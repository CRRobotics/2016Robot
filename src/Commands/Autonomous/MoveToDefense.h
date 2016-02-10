#ifndef MOVETODEFENSE_H
#define MOVETODEFENSE_H

//TODO Determine Constant
#define INCHESTODEFENSE 50

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class MoveToDefense: public CommandGroup
{
	public:
		MoveToDefense();

		virtual void Initialize();
		virtual void End();
		virtual void Interrupted();
	private:

};

#endif
