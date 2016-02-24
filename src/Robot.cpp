// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "Commands/Autonomous/CrossDefense.h"
#include "Commands/Autonomous/DriveToTargetAndShoot.h"
#include "Commands/Autonomous/FullAutonomous.h"
#include "Commands/Arm/ArmDriveToPos.h"
#include "Commands/Drive/SpeedDrive.h"
#include "Commands/Drive/JoystickFeedbackDrive.h"

#define TARGET_X 262.2154
#define TARGET_Y 550.6462


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Drive> Robot::drive;
std::shared_ptr<Acquisition> Robot::acquisition;
std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Scaling> Robot::scaling;
std::unique_ptr<OI> Robot::oi;
SendableChooser* Robot::autoPositionChooser;
SendableChooser* Robot::autoDefenseChooser;
std::shared_ptr<LEDs> Robot::leds;


// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    drive.reset(new Drive());
    acquisition.reset(new Acquisition());
    arm.reset(new Arm());
    scaling.reset(new Scaling());
    leds.reset(new LEDs(120));
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	autoDefenseChooser = new SendableChooser();
	autoDefenseChooser->AddDefault("Cheval de Frise", new CrossDefense(Defense::CHEVAL));
	autoDefenseChooser->AddObject("Drawbridge", new CrossDefense(Defense::DRAW));
	autoDefenseChooser->AddObject("Low Bar", new CrossDefense(Defense::LOW));
	autoDefenseChooser->AddObject("Moat", new CrossDefense(Defense::MOAT));
	autoDefenseChooser->AddObject("Porticullis", new CrossDefense(Defense::PORT));
	autoDefenseChooser->AddObject("Ramparts", new CrossDefense(Defense::RAMP));
	autoDefenseChooser->AddObject("Rough Terrain", new CrossDefense(Defense::ROUGH));
	autoDefenseChooser->AddObject("Sally Port", new CrossDefense(Defense::SALLY));
	autoDefenseChooser->AddObject("Rock Wall", new CrossDefense(Defense::WALL));

	autoPositionChooser = new SendableChooser();
	autoPositionChooser->AddDefault("1", new DriveToTargetAndShoot(1, TARGET_X, TARGET_Y));
	autoPositionChooser->AddObject("2", new DriveToTargetAndShoot(2, TARGET_X, TARGET_Y));
	autoPositionChooser->AddObject("3", new DriveToTargetAndShoot(3, TARGET_X, TARGET_Y));
	autoPositionChooser->AddObject("4", new DriveToTargetAndShoot(4, TARGET_X, TARGET_Y));
	autoPositionChooser->AddObject("5", new DriveToTargetAndShoot(5, TARGET_X, TARGET_Y));

	SmartDashboard::PutData("autonomous defense chooser", autoDefenseChooser);
	SmartDashboard::PutData("autonomous position chooser", autoPositionChooser);
//	SmartDashboard::PutNumber("arm_test_position", 400);
//	SmartDashboard::PutData("Arm To Test Pos", new ArmDriveToPos(Arm::Position::TEST));

	SmartDashboard::PutNumber("drive_p", 1);
	SmartDashboard::PutNumber("drive_i", 0);
	SmartDashboard::PutNumber("drive_d", 0);
	SmartDashboard::PutNumber("drive_f", 0);
	SmartDashboard::PutNumber("drive_test_speed", 1);
	SmartDashboard::PutData("Drive at Speed", new SpeedDrive(SmartDashboard::GetNumber("drive_test_speed", 0)));
	SmartDashboard::PutData("Joystick Feedback Drive", new JoystickFeedbackDrive());

	SmartDashboard::PutNumber("stick_deadband", .02);
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand.reset(new FullAutonomous());
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	SmartDashboard::PutBoolean("navx_callibrating", drive->ahrs->IsCalibrating());
	if (!drive->ahrs->IsCalibrating())
		SmartDashboard::PutNumber("navx_yaw", drive->GetYaw());
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

