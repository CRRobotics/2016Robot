################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Acquisition/AcquireBall.cpp \
../src/Commands/Acquisition/AutoEjectBall.cpp \
../src/Commands/Acquisition/EjectBall.cpp \
../src/Commands/Acquisition/IdleAcquisition.cpp 

OBJS += \
./src/Commands/Acquisition/AcquireBall.o \
./src/Commands/Acquisition/AutoEjectBall.o \
./src/Commands/Acquisition/EjectBall.o \
./src/Commands/Acquisition/IdleAcquisition.o 

CPP_DEPS += \
./src/Commands/Acquisition/AcquireBall.d \
./src/Commands/Acquisition/AutoEjectBall.d \
./src/Commands/Acquisition/EjectBall.d \
./src/Commands/Acquisition/IdleAcquisition.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Acquisition/%.o: ../src/Commands/Acquisition/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Driver\workspace/CodeRedRobot2016/src" -IC:\Users\Driver/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


