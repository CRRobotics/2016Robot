#include "Commands/Subsystem.h"
#include "../../Robot.h"


class FullAutonomous: public CommandGroup{
public:
	FullAutonomous(Robot::Defense defense, int defenseNum);
	void Initialize();
	void End();
	void Interrupted();
private:

};
