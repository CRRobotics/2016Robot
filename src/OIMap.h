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
#define SCL_MANUAL 6

//Arm
#define ARM_SCALE_POS 15
#define ARM_DRAW_POS 16
#define ARM_PORT_POS 8
#define ARM_DOWN_POS 9
#define ARM_SALLY_POS 10
#define ARM_SET_MODE 11
#define ARM_MANUAL 12
#define ARM_BUMP 1

//Drive
#define DRV_SHIFT_HIGH 11
#define DRV_SHIFT_LOW 6

#endif
