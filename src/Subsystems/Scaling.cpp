// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Scaling.h"
#include "../RobotMap.h"
#include "../Commands/Scaling/RunHookToPos.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Scaling::Scaling() : Subsystem("Scaling") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    scaleLift = RobotMap::scalingscaleLift;
    scaleLimit = RobotMap::scalingscaleLimit;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Scaling::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new RunHookToPos());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Scaling::SetExtendSpeed(int speed){
	scaleLift->SetControlMode(CANSpeedController::ControlMode::kSpeed);
	scaleLift->Set(speed);
}

void Scaling::ExtendToPoint(double point){
	scaleLift->SetControlMode(CANSpeedController::ControlMode::kPosition);
	scaleLift->Set(point);
}

int Scaling::GetScaleEnc(){
	return scaleLift->GetEncPosition();
}

bool Scaling::IsHome(){
	return scaleLimit->Get();
}

bool Scaling::IsExtendedToPoint(double point){
	return fabs(scaleLift->GetEncPosition() - point) < 0.2;
}

void Scaling::ResetScaling(){
	scaleLift->SetPosition(0);
}
