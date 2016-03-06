/*
 * LEDStrip.h
 *
 *  Created on: Feb 20, 2016
 *      Author: Paul
 */

#ifndef SRC_LEDSTRIP_H_
#define SRC_LEDSTRIP_H_

#include "Subsystems/LEDs.h"
#include "Robot.h"

class LEDStrip {
private:
	unsigned start;
	unsigned length;
	bool invert;
public:
	LEDStrip(unsigned start, unsigned end);
	virtual ~LEDStrip();

	struct color & operator[](std::size_t idx);
};

#endif /* SRC_LEDSTRIP_H_ */
