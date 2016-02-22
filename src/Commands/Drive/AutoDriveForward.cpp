// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoDriveForward.h"

#define ENC_LOW_SPEED_MAX 1250 * 2
#define ENC_HIGH_SPEED_MAX 4000 * 2

#define SLOW_DIST 12 * PULSE_PER_IN

AutoDriveForward::AutoDriveForward(double speed, double inches): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drive.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_lSpeed = speed;
	m_rSpeed = speed;
	m_lInches = inches;
	m_rInches = inches;
	m_lTicks = m_lInches * PULSE_PER_IN;
	m_rTicks = m_rInches * PULSE_PER_IN;
}

AutoDriveForward::AutoDriveForward(double lSpeed, double rSpeed, double lInches, double rInches): Command(){
	Requires(Robot::drive.get());
	m_lSpeed = lSpeed;
	m_rSpeed = rSpeed;
	m_lInches = lInches;
	m_lTicks = m_lInches * PULSE_PER_IN;
	m_rInches = rInches;
	m_rTicks = m_rInches * PULSE_PER_IN;
}

// Called just before this Command runs the first time
void AutoDriveForward::Initialize() {
	m_lTicks = SmartDashboard::GetNumber("auto_forward_in", 0) * PULSE_PER_IN;
	m_rTicks = SmartDashboard::GetNumber("auto_forward_in", 0) * PULSE_PER_IN;
	m_lSpeed = SmartDashboard::GetNumber("auto_forward_speed", 0);
	m_rSpeed = SmartDashboard::GetNumber("auto_forward_speed", 0);
	//TODO REMOVE LINES ABOVE, for testing only
	m_startTicksLeft = Robot::drive->GetLeftEnc();
	m_startTicksRight = Robot::drive->GetRightEnc();
	if (m_lTicks < 0)
	{
		m_lSpeed = m_lSpeed * -1;
		m_rSpeed = m_rSpeed * -1;
	}
	Robot::drive->ChangeControlMode(CANTalon::ControlMode::kSpeed);
	Robot::drive->SetDrivePID(SmartDashboard::GetNumber("drive_p", 1), SmartDashboard::GetNumber("drive_i", 0), SmartDashboard::GetNumber("drive_d", 0), SmartDashboard::GetNumber("drive_f", 0));

}

// Called repeatedly when this Command is scheduled to run
void AutoDriveForward::Execute() {
	int lTickDiff = fabs(Robot::drive->GetLeftEnc() - m_startTicksLeft) - fabs(m_lTicks);
	int rTickDiff = fabs(Robot::drive->GetRightEnc() - m_startTicksRight) - fabs(m_rTicks);
	if (lTickDiff < SLOW_DIST && rTickDiff < SLOW_DIST)
	{
		double lSlow = ((double)lTickDiff) / SLOW_DIST;
		double rSlow = ((double)rTickDiff) / SLOW_DIST;
		if (lSlow < 0.2)
			lSlow = 0.2;
		if (rSlow < 0.2)
			rSlow = 0.2;
		if (Robot::drive->GetHighGear())
		{
			Robot::drive->TankDrive(m_lSpeed * ENC_HIGH_SPEED_MAX * lSlow , m_rSpeed * ENC_HIGH_SPEED_MAX * rSlow);
		}
		else
		{
			Robot::drive->TankDrive(m_lSpeed * ENC_LOW_SPEED_MAX * lSlow, m_rSpeed * ENC_LOW_SPEED_MAX * rSlow);
		}
	}
	else
	{
		if (Robot::drive->GetHighGear())
		{
			Robot::drive->TankDrive(m_lSpeed * ENC_HIGH_SPEED_MAX, m_rSpeed * ENC_HIGH_SPEED_MAX);
		}
		else
		{
			Robot::drive->TankDrive(m_lSpeed * ENC_LOW_SPEED_MAX, m_rSpeed * ENC_LOW_SPEED_MAX);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForward::IsFinished() {
	return (fabs(Robot::drive->GetLeftEnc() - m_startTicksLeft) > fabs(m_lTicks) && fabs(Robot::drive->GetRightEnc() - m_startTicksRight) > fabs(m_rTicks));
}

// Called once after isFinished returns true
void AutoDriveForward::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveForward::Interrupted() {

}
