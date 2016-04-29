// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "JoystickScaleLimited.h"
#define SCALE_MAX_ENC -10000 + 200
#define SCALE_SLOW_START -7500
#define SCALE_MIN_ENC 0

JoystickScaleLimited::JoystickScaleLimited(): Command() {
	Requires(Robot::scaling.get());
	Requires(Robot::arm.get());
	m_startEnc = 0;
}


void JoystickScaleLimited::Initialize() {
	m_startEnc = Robot::scaling->GetScaleEnc();
}

void JoystickScaleLimited::Execute() {
	if (Robot::scaling->GetScaleEnc() > m_startEnc + SCALE_SLOW_START)//If its not in the slow zone
		Robot::scaling->SetExtendSpeed(Robot::oi->GetYControl());
	else//Robot is in the slow zone
	{
		if (Robot::oi->GetYControl() > 0)
		{
			double slow = fabs((Robot::scaling->GetScaleEnc() - m_startEnc - SCALE_SLOW_START)/((double)(SCALE_MAX_ENC - SCALE_SLOW_START)));
			if (Robot::scaling->GetScaleEnc() - m_startEnc < SCALE_MAX_ENC)
				slow = 0;
			Robot::scaling->SetExtendSpeed(Robot::oi->GetYControl() * slow);
		}
		else
		{
			Robot::scaling->SetExtendSpeed(Robot::oi->GetYControl());
		}
	}
	SmartDashboard::PutNumber("Scale Current", Robot::scaling->GetCurrent());
	SmartDashboard::PutNumber("Scale Enc", Robot::scaling->GetScaleEnc());
}

bool JoystickScaleLimited::IsFinished() {
    return false;
}

void JoystickScaleLimited::End() {
	Robot::scaling->SetExtendSpeed(0);
}

void JoystickScaleLimited::Interrupted() {
	Robot::scaling->SetExtendSpeed(0);
}
