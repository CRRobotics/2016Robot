################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AHRS/AHRS.cpp \
../src/AHRS/ContinuousAngleTracker.cpp \
../src/AHRS/InertialDataIntegrator.cpp \
../src/AHRS/OffsetTracker.cpp \
../src/AHRS/RegisterIO.cpp \
../src/AHRS/RegisterIOI2C.cpp \
../src/AHRS/RegisterIOSPI.cpp \
../src/AHRS/SerialIO.cpp 

OBJS += \
./src/AHRS/AHRS.o \
./src/AHRS/ContinuousAngleTracker.o \
./src/AHRS/InertialDataIntegrator.o \
./src/AHRS/OffsetTracker.o \
./src/AHRS/RegisterIO.o \
./src/AHRS/RegisterIOI2C.o \
./src/AHRS/RegisterIOSPI.o \
./src/AHRS/SerialIO.o 

CPP_DEPS += \
./src/AHRS/AHRS.d \
./src/AHRS/ContinuousAngleTracker.d \
./src/AHRS/InertialDataIntegrator.d \
./src/AHRS/OffsetTracker.d \
./src/AHRS/RegisterIO.d \
./src/AHRS/RegisterIOI2C.d \
./src/AHRS/RegisterIOSPI.d \
./src/AHRS/SerialIO.d 


# Each subdirectory must supply rules for building sources it contributes
src/AHRS/%.o: ../src/AHRS/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Driver\workspace/CodeRedRobot2016/src" -IC:\Users\Driver/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


