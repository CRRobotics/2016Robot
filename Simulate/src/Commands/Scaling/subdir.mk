################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Scaling/ExtendHook.cpp \
../src/Commands/Scaling/JoystickScale.cpp \
../src/Commands/Scaling/ResetHook.cpp \
../src/Commands/Scaling/RetractHook.cpp \
../src/Commands/Scaling/RunHookToPos.cpp 

OBJS += \
./src/Commands/Scaling/ExtendHook.o \
./src/Commands/Scaling/JoystickScale.o \
./src/Commands/Scaling/ResetHook.o \
./src/Commands/Scaling/RetractHook.o \
./src/Commands/Scaling/RunHookToPos.o 

CPP_DEPS += \
./src/Commands/Scaling/ExtendHook.d \
./src/Commands/Scaling/JoystickScale.d \
./src/Commands/Scaling/ResetHook.d \
./src/Commands/Scaling/RetractHook.d \
./src/Commands/Scaling/RunHookToPos.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Scaling/%.o: ../src/Commands/Scaling/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Driver\workspace/CodeRedRobot2016/src" -IC:\Users\Driver/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


