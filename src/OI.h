// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Joystick> m_cStick;
	std::shared_ptr<Joystick> m_rStick;
	std::shared_ptr<Joystick> m_lStick;

	//Acquisition
	std::shared_ptr<JoystickButton> m_acqIn;
	std::shared_ptr<JoystickButton> m_acqOut;

	//Drive
	std::shared_ptr<JoystickButton> m_drvShiftHigh;
	std::shared_ptr<JoystickButton> m_drvShiftLow;
	std::shared_ptr<JoystickButton> m_drvForwardL;
	std::shared_ptr<JoystickButton> m_drvForwardR;

	//AHRS
	std::shared_ptr<JoystickButton> m_resetNavX;

	//Arm
	std::shared_ptr<JoystickButton> m_armSetStart;
	std::shared_ptr<JoystickButton> m_armSetScale;
	std::shared_ptr<JoystickButton> m_armSetDraw;
	std::shared_ptr<JoystickButton> m_armSetSally;
	std::shared_ptr<JoystickButton> m_armSetPort;
	std::shared_ptr<JoystickButton> m_armSetDown;
	std::shared_ptr<JoystickButton> m_armSetManual;
	std::shared_ptr<JoystickButton> m_armBump;

	//Scaling
	std::shared_ptr<JoystickButton> m_sclExtend;
	std::shared_ptr<JoystickButton> m_sclRetract;
	std::shared_ptr<JoystickButton> m_sclSetManual;
	std::shared_ptr<JoystickButton> m_sclManualNoLimit;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<Joystick> getlJoystick();
	std::shared_ptr<Joystick> getrJoystick();
	std::shared_ptr<Joystick> getcJoystick();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<JoystickButton> m_drvTurnShootL;//Shoot on the left goal, not turn left
	std::shared_ptr<JoystickButton> m_drvTurnShootR;

	double GetYLeft();
	double GetYRight();
	double GetYControl();
	bool GetArmMan();
	bool GetSclMan();
	double GetDial();
};

#endif
