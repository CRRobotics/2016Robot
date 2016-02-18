/*
 * LEDs.h
 *
 *  Created on: Feb 17, 2016
 *      Author: adam
 */

#ifndef SRC_SUBSYSTEMS_LEDS_H_
#define SRC_SUBSYSTEMS_LEDS_H_

#include <SPI.h>
#include "WPILib.h"

struct __attribute__((packed)) color {
	uint8_t __brightness;
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

class LEDs : public Subsystem {
public:
	LEDs(unsigned number);
	virtual ~LEDs();

	void Refresh();
	void Resize(unsigned n);
	void InitDefaultCommand();

	struct color *colors; // this is an array
private:
	SPI *spi;
	unsigned number;

};
#endif /* SRC_SUBSYSTEMS_LEDS_H_ */
