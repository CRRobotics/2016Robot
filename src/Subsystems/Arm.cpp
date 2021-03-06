// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/Arm/JoystickArm.h"


#define ARM_MIN 28
#define ARM_LOW_SLOW 281
#define ARM_HIGH_SLOW 544
#define ARM_MAX 797
//#define ARM_HIGH_SLOW 725
//#define ARM_MAX 978

#define ARM_BUMP 60//TODO Update constant
#define ARM_LOWER 20//TODO Update constant

Arm::Arm() : Subsystem("Arm") {
    armPot = RobotMap::armarmPot;
    armLift = RobotMap::armarmLift;
    armHallTop = RobotMap::armarmHallTop;
    armHallBot = RobotMap::armarmHallBot;
    armAssist = RobotMap::armarmAssist;
    m_armLocked = false;
}

void Arm::InitDefaultCommand() {
	SetDefaultCommand(new JoystickArm());
}

void Arm::SetArmSpeed(double speed)
{
	ChangeControlMode(CANTalon::ControlMode::kPercentVbus);
	double slow = 1.0;
	if (GetArmPos() < ARM_LOW_SLOW && speed < 0){
		slow = (GetArmPos() -  ARM_MIN) / (ARM_LOW_SLOW - ARM_MIN);
		SmartDashboard::PutBoolean("Limiting Arm Speed", true);
	}
	else if (GetArmPos() > ARM_HIGH_SLOW && speed > 0){
		slow = (ARM_MAX - GetArmPos()) / (ARM_MAX - ARM_HIGH_SLOW);
		SmartDashboard::PutBoolean("Limiting Arm Speed", true);
	}
	else
		SmartDashboard::PutBoolean("Limiting Arm Speed", false);
	if (GetArmPos() < 73 && GetArmPos() > 70)
		slow = 0.75;
	armLift->Set(slow * speed);
}

bool Arm::IsArmTopLimit(){
	return armHallTop->Get();
}

bool Arm::IsArmBotLimit(){
	return armHallBot->Get();
}

double Arm::GetArmPos(){
	return armLift->GetAnalogInRaw();
}


bool Arm::IsArmAtPoint(Position pos){
	return fabs(GetArmPos() - GetPotValueForPos(pos)) < 8;
}

double Arm::GetPotValueForPos(Position pos){
	switch (pos)
	{
		case Position::POS_DOWN:
			return 60;
		break;
		case Position::POS_DRAW:
			return 200;
		break;
		case Position::LOWER:
			return GetArmPos() - ARM_LOWER;
		break;
		case Position::POS_PORT:
			return 468;
		break;
		case Position::POS_SALLY:
			return 200;
		break;
		case Position::POS_SCALE:
			return 940;
		break;
		case Position::BUMP:
			return GetArmPos() + ARM_BUMP;
		break;
		case Position::TEST:
			return SmartDashboard::GetNumber("arm_test_position", 400);
		case Position::POS_START:
			return 729;
		break;
		default:
			return 200;
	}
}

void Arm::ArmToPos(Position pos){
	ChangeControlMode(CANTalon::ControlMode::kPosition);
	armLift->Set(GetPotValueForPos(pos));
}

void Arm::SetArmLocked(bool locked){
	m_armLocked = locked;
}

bool Arm::IsArmLocked(){
	return m_armLocked;
}

void Arm::ChangeControlMode(CANTalon::ControlMode mode){
	armLift->SetControlMode(mode);
	if (mode == CANTalon::ControlMode::kPosition){
		armLift->SetPIDSourceType(PIDSourceType::kDisplacement);
		((std::shared_ptr<CANSpeedController>)armLift)->SetPID(10,0,0);
	}
}

void Arm::ArmAssist(bool high) {
	armAssist->Set(high);
}

double Arm::GetCurrent(){
	return armLift->GetOutputCurrent();
}
