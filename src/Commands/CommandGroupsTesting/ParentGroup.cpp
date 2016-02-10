
#include "ParentGroup.h"


ParentGroup::ParentGroup(std::shared_ptr<Command> existingCommands, std::shared_ptr<Command> commandToAdd): CommandGroup() {
	AddSequential(existingCommands.get());
	AddSequential(commandToAdd.get());
}

void ParentGroup::Initialize() {

}

void ParentGroup::Execute() {

}

bool ParentGroup::IsFinished() {
    return false;
}

void ParentGroup::End() {

}

void ParentGroup::Interrupted() {

}
