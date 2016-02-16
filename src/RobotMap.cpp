// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::drivelDrive1;
std::shared_ptr<CANTalon> RobotMap::drivelDrive2;
std::shared_ptr<CANTalon> RobotMap::driverDrive1;
std::shared_ptr<CANTalon> RobotMap::driverDrive2;
std::shared_ptr<Encoder> RobotMap::drivelEnc;
std::shared_ptr<Encoder> RobotMap::driverEnc;
std::shared_ptr<CANTalon> RobotMap::acquisitionacqRoller;
std::shared_ptr<DigitalInput> RobotMap::acquisitionacqSensor1;
std::shared_ptr<DigitalInput> RobotMap::acquisitionacqSensor2;
std::shared_ptr<AnalogPotentiometer> RobotMap::armarmPot;
std::shared_ptr<CANTalon> RobotMap::armarmLift;
std::shared_ptr<DigitalInput> RobotMap::armarmHallTop;
std::shared_ptr<DigitalInput> RobotMap::armarmHallBot;
std::shared_ptr<CANTalon> RobotMap::scalingscaleLift;
std::shared_ptr<Encoder> RobotMap::scalingscaleEnc;
std::shared_ptr<DigitalInput> RobotMap::scalingscaleLimit;
std::shared_ptr<Solenoid> RobotMap::driveshiftGear;
std::shared_ptr<Solenoid> RobotMap::armarmAssist;
//std::shared_ptr<AHRS> RobotMap::driveahrs;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    drivelDrive1.reset(new CANTalon(DRV_L1));
    lw->AddActuator("Drive", "lDrive1", drivelDrive1);
    
    drivelDrive2.reset(new CANTalon(DRV_L2));
    lw->AddActuator("Drive", "lDrive2", drivelDrive2);
    
    driverDrive1.reset(new CANTalon(DRV_R1));
    lw->AddActuator("Drive", "rDrive1", driverDrive1);
    
    driverDrive2.reset(new CANTalon(DRV_R2));
    lw->AddActuator("Drive", "rDrive2", driverDrive2);
    
    drivelDrive2->SetControlMode(CANSpeedController::ControlMode::kFollower);
    drivelDrive2->Set(DRV_L1);

    driverDrive2->SetControlMode(CANSpeedController::ControlMode::kFollower);
    driverDrive2->Set(DRV_R1);

    driverDrive1->ConfigEncoderCodesPerRev(4096);
    drivelDrive1->ConfigEncoderCodesPerRev(4096);

    driverDrive1->SetPIDSourceType(PIDSourceType::kRate);
    drivelDrive1->SetPIDSourceType(PIDSourceType::kRate);
    ((std::shared_ptr<CANSpeedController>)driverDrive1)->SetPID(DRV_R_P,DRV_R_I,DRV_R_D);
    ((std::shared_ptr<CANSpeedController>)drivelDrive1)->SetPID(DRV_L_P,DRV_L_D,DRV_L_D);


//    drivelEnc.reset(new Encoder(0, 1, false, Encoder::k4X));
//    lw->AddSensor("Drive", "lEnc", drivelEnc);
//    drivelEnc->SetDistancePerPulse(1.0);
//    drivelEnc->SetPIDSourceType(PIDSourceType::kRate);
//    driverEnc.reset(new Encoder(2, 3, false, Encoder::k4X));
//    lw->AddSensor("Drive", "rEnc", driverEnc);
//    driverEnc->SetDistancePerPulse(1.0);
//    driverEnc->SetPIDSourceType(PIDSourceType::kRate);
    acquisitionacqRoller.reset(new CANTalon(ACQ_ROLLER));
    lw->AddActuator("Acquisition", "acqRoller", acquisitionacqRoller);
    
    acquisitionacqSensor1.reset(new DigitalInput(ACQ_DI1));
    lw->AddSensor("Acquisition", "acqSensor1", acquisitionacqSensor1);
    
    acquisitionacqSensor2.reset(new DigitalInput(ACQ_DI2));
    lw->AddSensor("Acquisition", "acqSensor2", acquisitionacqSensor2);
    
    armarmPot.reset(new AnalogPotentiometer(ARM_POT, 4096.0, 0.0));
    lw->AddSensor("Arm", "armPot", armarmPot);
    
    armarmLift.reset(new CANTalon(ARM_LIFT));
    armarmLift->SetPIDSourceType(PIDSourceType::kDisplacement);
    ((std::shared_ptr<CANSpeedController>)armarmLift)->SetPID(ARM_LIFT_P, ARM_LIFT_I, ARM_LIFT_D);
    lw->AddActuator("Arm", "armLift", armarmLift);
    //armarmLift->ConfigFwdLimitSwitchNormallyOpen(false);
    //armarmLift->ConfigRevLimitSwitchNormallyOpen(false);
    
    armarmHallTop.reset(new DigitalInput(ARM_HALL_TOP));
    lw->AddSensor("Arm", "armHallTop", armarmHallTop);
    
    armarmHallBot.reset(new DigitalInput(ARM_HALL_BOT));
    lw->AddSensor("Arm", "armHallBot", armarmHallBot);
    
    scalingscaleLift.reset(new CANTalon(SCL_LFT));
    lw->AddActuator("Scaling", "scaleLift", scalingscaleLift);
    
//    scalingscaleEnc.reset(new Encoder(8, 9, false, Encoder::k4X));
//    lw->AddSensor("Scaling", "scaleEnc", scalingscaleEnc);
//    scalingscaleEnc->SetDistancePerPulse(1.0);
//    scalingscaleEnc->SetPIDSourceType(PIDSourceType::kDisplacement);

    scalingscaleLimit.reset(new DigitalInput(SCL_LMT));
    lw->AddSensor("Scaling", "scaleLimit", scalingscaleLimit);
    
    scalingscaleLift->ConfigEncoderCodesPerRev(4096);

    scalingscaleLift->SetPIDSourceType(PIDSourceType::kDisplacement);
    ((std::shared_ptr<CANSpeedController>)scalingscaleLift)->SetPID(SCL_LIFT_P,SCL_LIFT_I,SCL_LIFT_D);

    driveshiftGear.reset(new Solenoid(DRV_SHIFT));

    armarmAssist.reset(new Solenoid(2));

//    driveahrs.reset(new AHRS(SPI::kMXP));
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
