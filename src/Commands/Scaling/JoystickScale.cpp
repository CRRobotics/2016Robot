// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "JoystickScale.h"
#define SCALE_MAX_ENC -10000 + 200
#define SCALE_MIN_ENC 0

JoystickScale::JoystickScale(): Command() {
	Requires(Robot::scaling.get());
	Requires(Robot::arm.get());
}


void JoystickScale::Initialize() {

}

void JoystickScale::Execute() {
//	if (!(Robot::oi->GetYControl() < 0 && Robot::scaling->GetScaleEnc() < SCALE_MAX_ENC)
//		&& !(Robot::oi->GetYControl() > 0 && Robot::scaling->GetScaleEnc() > SCALE_MIN_ENC))
		Robot::scaling->SetExtendSpeed(Robot::oi->GetYControl());
	SmartDashboard::PutNumber("Scale Current", Robot::scaling->GetCurrent());
	SmartDashboard::PutNumber("Scale Enc", Robot::scaling->GetScaleEnc());
}

bool JoystickScale::IsFinished() {
    return false;
}

void JoystickScale::End() {
	Robot::scaling->SetExtendSpeed(0);
}

void JoystickScale::Interrupted() {
	Robot::scaling->SetExtendSpeed(0);
}
