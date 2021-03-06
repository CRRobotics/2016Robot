// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AHRS/ResetDisplacement.h"
#include "Commands/Acquisition/AcquireBall.h"
#include "Commands/Arm/ArmDriveToPos.h"
#include "Commands/Acquisition/EjectBall.h"
#include "Commands/Scaling/ExtendHook.h"
#include "Commands/Arm/JoystickArm.h"
#include "Commands/Drive/JoystickDrive.h"
#include "Commands/Arm/ResetArm.h"
#include "Commands/Scaling/ResetHook.h"
#include "Commands/Scaling/RetractHook.h"
#include "Commands/Drive/AutoDriveForward.h"
#include "Commands/Drive/AutoDriveTurn.h"
#include "Commands/Drive/ShiftHigh.h"
#include "Commands/Drive/ShiftLow.h"
#include "Commands/Drive/JoystickDriveForwardL.h"
#include "Commands/Drive/JoystickDriveForwardR.h"
#include "Commands/Scaling/JoystickScale.h"
#include "Commands/Scaling/JoystickScaleLimited.h"
#include "Subsystems/Arm.h"
#include "OIMap.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    m_cStick.reset(new Joystick(2));
    
    m_rStick.reset(new Joystick(1));
    
    m_lStick.reset(new Joystick(0));
    
    m_acqIn.reset(new JoystickButton(m_cStick.get(), ACQ_IN));
    m_acqOut.reset(new JoystickButton(m_cStick.get(), ACQ_OUT));

    m_drvShiftHigh.reset(new JoystickButton(m_rStick.get(), DRV_SHIFT_HIGH));
    m_drvShiftLow.reset(new JoystickButton(m_lStick.get(), DRV_SHIFT_LOW));
    m_drvForwardL.reset(new JoystickButton(m_lStick.get(), DRV_FORWARD));
    m_drvForwardR.reset(new JoystickButton(m_rStick.get(), DRV_FORWARD));
    m_drvTurnShootL.reset(new JoystickButton(m_lStick.get(), DRV_TURN_SHOOTL));
    m_drvTurnShootR.reset(new JoystickButton(m_rStick.get(), DRV_TURN_SHOOTR));

    m_armSetScale.reset(new JoystickButton(m_cStick.get(), ARM_SCALE_POS));
    m_armSetDraw.reset(new JoystickButton(m_cStick.get(),  ARM_DRAW_POS));
    m_armSetSally.reset(new JoystickButton(m_cStick.get(), ARM_SALLY_POS));
    m_armSetPort.reset(new JoystickButton(m_cStick.get(),  ARM_PORT_POS));
    m_armSetDown.reset(new JoystickButton(m_cStick.get(),  ARM_DOWN_POS));
    m_armSetManual.reset(new JoystickButton(m_cStick.get(),ARM_MANUAL));
    m_armBump.reset(new JoystickButton(m_cStick.get(), ARM_BUMP));
    m_armSetStart.reset(new JoystickButton(m_cStick.get(), ARM_START_POS));

    m_sclExtend.reset(new JoystickButton(m_cStick.get(), SCL_EXTEND));
    m_sclRetract.reset(new JoystickButton(m_cStick.get(), SCL_RETRACT));
    m_sclSetManual.reset(new JoystickButton(m_cStick.get(), SCL_MANUAL));
    m_sclManualNoLimit.reset(new JoystickButton(m_cStick.get(), SCL_NOLIMIT));

    m_resetNavX.reset(new JoystickButton(m_cStick.get(), AHRS_RESET));

    // SmartDashboard Buttons
    SmartDashboard::PutData("ResetArm", new ResetArm());
    SmartDashboard::PutData("ResetHook", new ResetHook());

    m_acqIn->WhileHeld(new AcquireBall());
    m_acqOut->WhileHeld(new EjectBall());

    m_drvShiftHigh->WhenPressed(new ShiftHigh());
    m_drvShiftLow->WhenPressed(new ShiftLow());
    m_drvForwardL->WhileHeld(new JoystickDriveForwardL());
    m_drvForwardR->WhileHeld(new JoystickDriveForwardR());
    m_drvTurnShootL->WhenPressed(new AutoDriveTurn(60));
    m_drvTurnShootR->WhenPressed(new AutoDriveTurn(-60));

    m_resetNavX->WhenPressed(new ResetDisplacement());

    m_armSetDown->WhenPressed(new ArmDriveToPos(Arm::Position::POS_DOWN));
    m_armSetDraw->WhenPressed(new ArmDriveToPos(Arm::Position::POS_DRAW));
    m_armSetPort->WhenPressed(new ArmDriveToPos(Arm::Position::POS_PORT));
    m_armSetScale->WhenPressed(new ArmDriveToPos(Arm::Position::POS_SCALE));
    m_armSetSally->WhenPressed(new ArmDriveToPos(Arm::Position::POS_SALLY));
    m_armBump->WhenPressed(new ArmDriveToPos(Arm::Position::BUMP));
    m_armSetStart->WhenPressed(new ArmDriveToPos(Arm::Position::POS_START));

    m_sclExtend->WhileHeld(new ExtendHook());
    m_sclRetract->WhileHeld(new RetractHook());
    m_sclManualNoLimit->WhileHeld(new JoystickScale());
    m_sclSetManual->WhileHeld(new JoystickScaleLimited());


    //AutoTurn Testing
    SmartDashboard::PutNumber("turn_p_coeff", 0.06);
    SmartDashboard::PutNumber("turn_d_coeff", 0.0);
    SmartDashboard::PutNumber("turn_i_coeff", 0.0);

    SmartDashboard::PutNumber("auto_turn_test_angle", 90);
    SmartDashboard::PutData("test_auto_turn", new AutoDriveTurn(SmartDashboard::GetNumber("auto_turn_test_angle", 0)));

    //Arm PID Testing
    SmartDashboard::PutNumber("arm_p_coeff", .01);
    SmartDashboard::PutNumber("arm_i_coeff", .01);
    SmartDashboard::PutNumber("arm_d_coeff", .01);

    //Scaling PID Testing
    SmartDashboard::PutNumber("scl_p_coeff", .01);
    SmartDashboard::PutNumber("scl_i_coeff", .01);
    SmartDashboard::PutNumber("scl_d_coeff", .01);

    //AutoDriveForward Testing
    SmartDashboard::PutNumber("auto_forward_in", 12);
    SmartDashboard::PutData("Drive Forward", new AutoDriveForward(0,0));
    SmartDashboard::PutNumber("auto_forward_speed", 0.5);

    SmartDashboard::PutData("Reset NavX", new ResetDisplacement());
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getlJoystick() {
   return m_lStick;
}

std::shared_ptr<Joystick> OI::getrJoystick() {
   return m_rStick;
}

std::shared_ptr<Joystick> OI::getcJoystick() {
   return m_cStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

double OI::GetYLeft(){
	double value = m_lStick->GetY();
	if(fabs(value) < .02){//SmartDashboard::GetNumber("stick_deadband", .02)) {
		return 0;
	}
	else {
		return value;
	}
}
double OI::GetXLeft()
{
	double value = m_lStick->GetX();
	if(fabs(value) < .02){//SmartDashboard::GetNumber("stick_deadband", .02)) {
		return 0;
	}
	else {
		return value;
	}
}

double OI::GetYRight(){
	double value = m_rStick->GetY();
	if(fabs(value) < .02){//SmartDashboard::GetNumber("stick_deadband", .02)) {
		return 0;
	}
	else {
		return value;
	}
}

double OI::GetYControl(){
	double value = m_cStick->GetY();
	if(fabs(value) < .05) {
		return 0;
	}
	else {
		return value;
	}
}

bool OI::GetArmMan(){
	return m_armSetManual->Get();
}

bool OI::GetSclMan(){
	return m_sclSetManual->Get();
}

double OI::GetDial(){
	return m_cStick->GetRawAxis(1) * 1;
}

