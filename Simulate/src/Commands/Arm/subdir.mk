################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Arm/ArmDriveToPos.cpp \
../src/Commands/Arm/JoystickArm.cpp \
../src/Commands/Arm/ResetArm.cpp 

OBJS += \
./src/Commands/Arm/ArmDriveToPos.o \
./src/Commands/Arm/JoystickArm.o \
./src/Commands/Arm/ResetArm.o 

CPP_DEPS += \
./src/Commands/Arm/ArmDriveToPos.d \
./src/Commands/Arm/JoystickArm.d \
./src/Commands/Arm/ResetArm.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Arm/%.o: ../src/Commands/Arm/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Driver\workspace/CodeRedRobot2016/src" -IC:\Users\Driver/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


