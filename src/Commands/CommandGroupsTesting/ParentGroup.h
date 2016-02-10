#ifndef PARENTGROUP_H
#define PARENTGROUP_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

class ParentGroup: public CommandGroup
{
	public:
		ParentGroup(std::shared_ptr<Command> existingCommands, std::shared_ptr<Command> commandToAdd);

		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
	private:

};

#endif
