// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "AHRS/AHRS.h"

#define ARM_ASSIST_POINT 50

#define ARM_LIFT_P 1
#define ARM_LIFT_I 0
#define ARM_LIFT_D 0

#define SCL_LIFT_P 1
#define SCL_LIFT_I 0
#define SCL_LIFT_D 0

#define DRV_L_P 1
#define DRV_L_I 0
#define DRV_L_D 0

#define DRV_R_P DRV_L_P
#define DRV_R_I DRV_L_I
#define DRV_R_D	DRV_L_D

#define DRV_L1 4
#define DRV_L2 3
#define DRV_R1 6
#define DRV_R2 5

#define DRV_SHIFT 0

#define ARM_LIFT 2
#define ARM_HALL_TOP 6
#define ARM_HALL_BOT 7
#define ARM_POT 0

#define ACQ_ROLLER 7
#define ACQ_DI1 4
#define ACQ_DI2 5

#define SCL_LFT 8
#define SCL_LMT 10


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<CANTalon> drivelDrive1;
	static std::shared_ptr<CANTalon> drivelDrive2;
	static std::shared_ptr<CANTalon> driverDrive1;
	static std::shared_ptr<CANTalon> driverDrive2;
	static std::shared_ptr<Encoder> drivelEnc;
	static std::shared_ptr<Encoder> driverEnc;
	static std::shared_ptr<CANTalon> acquisitionacqRoller;
	static std::shared_ptr<DigitalInput> acquisitionacqSensor1;
	static std::shared_ptr<DigitalInput> acquisitionacqSensor2;
	static std::shared_ptr<AnalogPotentiometer> armarmPot;
	static std::shared_ptr<CANTalon> armarmLift;
	static std::shared_ptr<DigitalInput> armarmHallTop;
	static std::shared_ptr<DigitalInput> armarmHallBot;
	static std::shared_ptr<CANTalon> scalingscaleLift;
	static std::shared_ptr<Encoder> scalingscaleEnc;
	static std::shared_ptr<DigitalInput> scalingscaleLimit;
	static std::shared_ptr<Solenoid> driveshiftGear;
	static std::shared_ptr<Solenoid> armarmAssist;
	static std::shared_ptr<AHRS> driveahrs;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();
};
#endif
