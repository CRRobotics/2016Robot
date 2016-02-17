/*
 * LEDs.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: adam
 */

#include "LEDs.h"
#include <SPI.h>
#include <algorithm>

LEDs::LEDs(unsigned number) : Subsystem("LEDs") {
	// TODO Auto-generated constructor stub
	this->number = number;
	colors = calloc(number, sizeof(struct color));
	spi = new SPI(Port.kOnboardCS0);
	spi->SetClockRate(4000000);
	for(int i = 0; i < number; i++){
		colors[i].__brightness = 0xff;
	}
}

LEDs::~LEDs() {
	free(colors);
	delete spi;
	// TODO Auto-generated destructor stub
}

void LEDs::Refresh() {
	uint8_t *c = (uint8_t *)colors;
	int size = number * sizeof(struct color);
	for(unsigned i = 0; i < size; i += 128){
		spi->Write(c + i, std::min(size - i, 128));
	}
}

void LEDs::Resize(unsigned n){
	colors = realloc(colors, n * sizeof(struct color));
	for(int i = number; i < n; i++){
		colors[i].__brightness = 0xff;
	}
	number = n;
}
