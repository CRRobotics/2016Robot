// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "JoystickFeedbackDrive.h"

#define ENC_LOW_SPEED_MAX 1250 * 2
#define ENC_HIGH_SPEED_MAX 4000 * 2

JoystickFeedbackDrive::JoystickFeedbackDrive(): Command() {
        // Use requires() here to declare subsystem dependencies
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drive.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void JoystickFeedbackDrive::Initialize() {
	Robot::drive->ChangeControlMode(CANTalon::ControlMode::kSpeed);
	Robot::drive->SetDrivePID(SmartDashboard::GetNumber("drive_p", 1), SmartDashboard::GetNumber("drive_i", 0), SmartDashboard::GetNumber("drive_d", 0), SmartDashboard::GetNumber("drive_f", 0));
}

// Called repeatedly when this Command is scheduled to run
void JoystickFeedbackDrive::Execute() {
	double joystickCurveL = Robot::oi->GetYLeft() * fabs(Robot::oi->GetYLeft());
	double joystickCurveR = Robot::oi->GetYRight() * fabs(Robot::oi->GetYRight());
	if (Robot::drive->GetHighGear())
	{
		Robot::drive->TankDrive(joystickCurveL * ENC_HIGH_SPEED_MAX, joystickCurveR * ENC_HIGH_SPEED_MAX);
	}
	else
	{
		Robot::drive->TankDrive(joystickCurveL * ENC_LOW_SPEED_MAX, joystickCurveR * ENC_LOW_SPEED_MAX);
	}
	SmartDashboard::PutNumber("lDriveEnc_speed", Robot::drive->GetLEncSpeed());
	SmartDashboard::PutNumber("rDriveEnc_speed", Robot::drive->GetREncSpeed());
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickFeedbackDrive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void JoystickFeedbackDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickFeedbackDrive::Interrupted() {

}
