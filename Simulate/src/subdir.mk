################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LEDStrip.cpp \
../src/OI.cpp \
../src/Robot.cpp \
../src/RobotMap.cpp 

OBJS += \
./src/LEDStrip.o \
./src/OI.o \
./src/Robot.o \
./src/RobotMap.o 

CPP_DEPS += \
./src/LEDStrip.d \
./src/OI.d \
./src/Robot.d \
./src/RobotMap.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Driver\workspace/CodeRedRobot2016/src" -IC:\Users\Driver/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


