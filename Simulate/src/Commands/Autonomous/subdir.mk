################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Autonomous/CrossDefense.cpp \
../src/Commands/Autonomous/DriveToAndCrossLowBar.cpp \
../src/Commands/Autonomous/DriveToTargetAndShoot.cpp \
../src/Commands/Autonomous/FullAutonomous.cpp \
../src/Commands/Autonomous/MoveToDefense.cpp 

OBJS += \
./src/Commands/Autonomous/CrossDefense.o \
./src/Commands/Autonomous/DriveToAndCrossLowBar.o \
./src/Commands/Autonomous/DriveToTargetAndShoot.o \
./src/Commands/Autonomous/FullAutonomous.o \
./src/Commands/Autonomous/MoveToDefense.o 

CPP_DEPS += \
./src/Commands/Autonomous/CrossDefense.d \
./src/Commands/Autonomous/DriveToAndCrossLowBar.d \
./src/Commands/Autonomous/DriveToTargetAndShoot.d \
./src/Commands/Autonomous/FullAutonomous.d \
./src/Commands/Autonomous/MoveToDefense.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Autonomous/%.o: ../src/Commands/Autonomous/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Driver\workspace/CodeRedRobot2016/src" -IC:\Users\Driver/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


