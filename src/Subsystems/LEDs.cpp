/*
 * LEDs.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: adam
 */

#include "LEDs.h"
#include "../Commands/LEDs/LEDRefresh.h"
#include <algorithm>
#include <vector>

LEDs::LEDs(unsigned number) : Subsystem("LEDs") {
	// TODO Auto-generated constructor stub
	this->number = number;
	this->offset = 0;
	colors = new std::vector<struct color>(number);
	spif = fopen("/dev/spidev0.0", "wb");
	for(unsigned i = 0; i < number; i++){
		(*colors)[i].__brightness = 0xff;
		(*colors)[i].r = 0;
		(*colors)[i].g = 0;
		(*colors)[i].b = 0;
	}
}

void LEDs::InitDefaultCommand(){
	SetDefaultCommand(new LEDRefresh());
}

LEDs::~LEDs() {
	delete colors;
	fclose(spif);
	// TODO Auto-generated destructor stub
}

void LEDs::Refresh() {
	//fprintf(stderr, "refresh\n");
	offset++;
	offset %= 88;
	struct color *c = colors->data();
	//for(unsigned i = 0; i < size; i += 128){
	//	spi->Write(c + i, (unsigned char)std::min((unsigned)(size - i), (unsigned)128));
	//}
	//fwrite("\x00\x00\x00\x00", 4, 1, spif);
	int a = 0, b = 0;
	if(number != offset) a = fwrite(c + offset, sizeof(struct color), number-offset, spif);
	if(offset != 0) b = fwrite(c, sizeof(struct color), offset, spif);
	fprintf(stderr, "%d %d  %d %d %d\n", number, offset, a, b, a+b);

	fwrite("\xff\xff\xff\xff", 4, 1, spif);
	fflush(spif);
}

void LEDs::Resize(unsigned n){
	colors->resize(n);
	for(unsigned i = number; i < n; i++){
		(*colors)[i].__brightness = 0xff;
	}
	number = n;
}
