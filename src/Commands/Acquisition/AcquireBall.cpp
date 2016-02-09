// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AcquireBall.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AcquireBall::AcquireBall(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::acquisition.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AcquireBall::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AcquireBall::Execute() {
	Robot::acquisition->SetRollSpeed(-.6);//TODO: Maybe change 1.0 to something better and negate
}

// Make this return true when this Command no longer needs to run execute()
bool AcquireBall::IsFinished() {
    return false; //Robot::acquisition->IsBallAcquired();
}

// Called once after isFinished returns true
void AcquireBall::End() {
	Robot::acquisition->SetRollSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AcquireBall::Interrupted() {
	Robot::acquisition->SetRollSpeed(0);
}
