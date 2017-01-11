################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/Acquisition.cpp \
../src/Subsystems/Arm.cpp \
../src/Subsystems/Drive.cpp \
../src/Subsystems/LEDs.cpp \
../src/Subsystems/Scaling.cpp 

OBJS += \
./src/Subsystems/Acquisition.o \
./src/Subsystems/Arm.o \
./src/Subsystems/Drive.o \
./src/Subsystems/LEDs.o \
./src/Subsystems/Scaling.o 

CPP_DEPS += \
./src/Subsystems/Acquisition.d \
./src/Subsystems/Arm.d \
./src/Subsystems/Drive.d \
./src/Subsystems/LEDs.d \
./src/Subsystems/Scaling.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Driver\workspace/CodeRedRobot2016/src" -IC:\Users\Driver/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


