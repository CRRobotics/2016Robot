################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Drive/AutoDriveForward.cpp \
../src/Commands/Drive/AutoDriveTurn.cpp \
../src/Commands/Drive/JoystickDrive.cpp \
../src/Commands/Drive/JoystickFeedbackDrive.cpp \
../src/Commands/Drive/ShiftHigh.cpp \
../src/Commands/Drive/ShiftLow.cpp \
../src/Commands/Drive/SpeedDrive.cpp 

OBJS += \
./src/Commands/Drive/AutoDriveForward.o \
./src/Commands/Drive/AutoDriveTurn.o \
./src/Commands/Drive/JoystickDrive.o \
./src/Commands/Drive/JoystickFeedbackDrive.o \
./src/Commands/Drive/ShiftHigh.o \
./src/Commands/Drive/ShiftLow.o \
./src/Commands/Drive/SpeedDrive.o 

CPP_DEPS += \
./src/Commands/Drive/AutoDriveForward.d \
./src/Commands/Drive/AutoDriveTurn.d \
./src/Commands/Drive/JoystickDrive.d \
./src/Commands/Drive/JoystickFeedbackDrive.d \
./src/Commands/Drive/ShiftHigh.d \
./src/Commands/Drive/ShiftLow.d \
./src/Commands/Drive/SpeedDrive.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Drive/%.o: ../src/Commands/Drive/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Driver\workspace/CodeRedRobot2016/src" -IC:\Users\Driver/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


