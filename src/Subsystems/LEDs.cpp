/*
 * LEDs.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: adam
 */

#include "LEDs.h"
#include "../Commands/LEDs/LEDRefresh.h"
#include <algorithm>

LEDs::LEDs(unsigned number) : Subsystem("LEDs") {
	// TODO Auto-generated constructor stub
	this->number = number;
	colors = (struct color *) calloc(number, sizeof(struct color));
	spi = new SPI(SPI::Port::kOnboardCS0);
	spi->SetClockRate(4000000);
	for(unsigned i = 0; i < number; i++){
		colors[i].__brightness = 0xff;
	}
}

void LEDs::InitDefaultCommand(){
	SetDefaultCommand(new LEDRefresh());
}

LEDs::~LEDs() {
	free(colors);
	delete spi;
	// TODO Auto-generated destructor stub
}

void LEDs::Refresh() {
	uint8_t *c = (uint8_t *)colors;
	unsigned size = number * sizeof(struct color);
	for(unsigned i = 0; i < size; i += 128){
		spi->Write(c + i, (unsigned char)std::min((unsigned)(size - i), (unsigned)128));
	}
}

void LEDs::Resize(unsigned n){
	colors = (struct color *)realloc(colors, n * sizeof(struct color));
	for(unsigned i = number; i < n; i++){
		colors[i].__brightness = 0xff;
	}
	number = n;
}
