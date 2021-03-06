// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RetractHook.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RetractHook::RetractHook(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::scaling.get());
//	Requires(Robot::arm.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void RetractHook::Initialize() {
	Robot::scaling->ResetOffset();
}

// Called repeatedly when this Command is scheduled to run
void RetractHook::Execute() {
	Robot::scaling->ExtendToPoint(Scaling::Position::POS_RETRACTED);//TODO: Replace 1.0 with constant for scaling
}

// Make this return true when this Command no longer needs to run execute()
bool RetractHook::IsFinished() {
    return Robot::scaling->IsExtendedToPoint(Scaling::Position::POS_RETRACTED);//TODO: Replace 1.0 with constant for scaling
}

// Called once after isFinished returns true
void RetractHook::End() {
	Robot::scaling->SetExtendSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RetractHook::Interrupted() {
	Robot::scaling->SetExtendSpeed(0);
}
