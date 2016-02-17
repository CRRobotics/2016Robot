// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ARM_H
#define ARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Arm: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<AnalogPotentiometer> armPot;
	std::shared_ptr<CANTalon> armLift;
	std::shared_ptr<DigitalInput> armHallTop;
	std::shared_ptr<DigitalInput> armHallBot;
	std::shared_ptr<Solenoid> armAssist;
	bool m_armLocked;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:

	enum class Position {
		POS_DOWN,
		POS_PORT,
		POS_SALLY,
		POS_DRAW,
		POS_SCALE,
		BUMP,
		LOWER
	};

	Arm();
	void InitDefaultCommand();
	void SetArmSpeed(double speed);
	void ArmToPos(Position pos);
	bool IsArmAtPoint(Position pos);
	bool IsArmTopLimit();
	bool IsArmBotLimit();
	double GetArmPos();
	double GetPotValueForPos(Position pos);
	void SetArmLocked(bool locked);
	bool IsArmLocked();
	void ChangeControlMode(CANTalon::ControlMode mode);
	void ArmAssist(bool up);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
