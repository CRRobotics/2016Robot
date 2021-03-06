#ifndef OIMAP_H
#define OIMAP_H

/* Naming scheme for ports:
* "Subsystem_Type_Function"
*
* Subsystem:
* ACQ - Acquisition
* RBT - No subsystem
* DRV - Drive
* SCL - Scaling
* ARM - Arm
*
* JOY - Joystick
* ANA - Analog input
* DIN - Digital input
* DOT - Digital output
*/

//Acquisition
#define ACQ_IN 4
#define ACQ_OUT 5

//Scaling
#define SCL_EXTEND 6
#define SCL_RETRACT 7
#define SCL_MANUAL 8
#define SCL_NOLIMIT 1

//Arm
#define ARM_SCALE_POS 11
#define ARM_DRAW_POS 20
#define ARM_PORT_POS 20
#define ARM_DOWN_POS 20
#define ARM_SALLY_POS 20
#define ARM_SET_MODE 20
#define ARM_MANUAL 20
#define ARM_BUMP 20
#define ARM_START_POS 9

//Drive
#define DRV_SHIFT_HIGH 11
#define DRV_SHIFT_LOW 6
#define DRV_FORWARD 1
#define DRV_TURN_SHOOTL 7
#define DRV_TURN_SHOOTR 10

//AHRS
#define AHRS_RESET 20

#endif
