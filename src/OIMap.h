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
#define ACQ_IN 1
#define ACQ_OUT 2

//Scaling
#define SCL_EXTEND 3
#define SCL_RETRACT 4

//Arm
#define ARM_SCALE_POS 5
#define ARM_DRAW_POS 6
#define ARM_PORT_POS 7
#define ARM_DOWN_POS 8
#define ARM_SALLY_POS 9
#define ARM_SET_MODE 10
#define ARM_KNOB 11

//Drive
#define DRV_SHIFT_HIGHT 12
#define DRV_SHIFT_LOW 13

#endif
