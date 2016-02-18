// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Subsystems/Acquisition.h"
#include "Subsystems/Arm.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Scaling.h"
#include "Subsystems/LEDs.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"

class Robot : public IterativeRobot {
public:

	enum class Defense
	{
		PORT,	CHEVAL,
		MOAT,	RAMP,
		DRAW,	SALLY,
		WALL,	ROUGH,
		LOW

	};

	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    static std::shared_ptr<Drive> drive;
    static std::shared_ptr<Acquisition> acquisition;
    static std::shared_ptr<Arm> arm;
    static std::shared_ptr<Scaling> scaling;
    static std::shared_ptr<SendableChooser> autoPositionChooser;
    static std::shared_ptr<SendableChooser> autoDefenseChooser;
    static std::shared_ptr<LEDs> leds;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
