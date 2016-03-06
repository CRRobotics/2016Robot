/*
 * LEDStrip.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: Paul
 */

#include "LEDStrip.h"
#include <cstdlib>

LEDStrip::LEDStrip(unsigned start, unsigned end) {
	// TODO Auto-generated constructor stub
	invert = start > end;
	length = std::abs(start - end);
	this->start = start;
}

LEDStrip::~LEDStrip() {
	// TODO Auto-generated destructor stub
}

struct color & LEDStrip::operator[](std::size_t idx){
	return Robot::leds->colors->at(start + (invert ? -idx : idx));
}
