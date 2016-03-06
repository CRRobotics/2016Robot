/*
 * LEDs.h
 *
 *  Created on: Feb 17, 2016
 *      Author: adam
 */

#ifndef SRC_SUBSYSTEMS_LEDS_H_
#define SRC_SUBSYSTEMS_LEDS_H_

#include "WPILib.h"
#include <stdio.h>
#include <unistd.h>

struct __attribute__((packed)) color {
	uint8_t __brightness;
	uint8_t b;
	uint8_t g;
	uint8_t r;
};

class LEDs : public Subsystem {
public:
	LEDs(unsigned number);
	virtual ~LEDs();

	void Refresh();
	void Resize(unsigned n);
	void InitDefaultCommand();

	std::vector<struct color> *colors;
private:
	FILE *spif;
	unsigned number;

};
#endif /* SRC_SUBSYSTEMS_LEDS_H_ */
