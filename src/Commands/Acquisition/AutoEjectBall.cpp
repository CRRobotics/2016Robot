// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoEjectBall.h"

#define SECONDS_EJECT_ON 5

AutoEjectBall::AutoEjectBall(): Command() {
	Requires(Robot::acquisition.get());
}

// Called just before this Command runs the first time
void AutoEjectBall::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoEjectBall::Execute() {
	Robot::acquisition->SetRollSpeed(1);//TODO: Maybe negate
}

// Make this return true when this Command no longer needs to run execute()
bool AutoEjectBall::IsFinished() {
    return TimeSinceInitialized() > SECONDS_EJECT_ON;
}

// Called once after isFinished returns true
void AutoEjectBall::End() {
	Robot::acquisition->SetRollSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoEjectBall::Interrupted() {
	Robot::acquisition->SetRollSpeed(0);
}
