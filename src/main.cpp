#include <Arduino.h>
#include <NeoPixel.h>
#include "Pixels.h"
#include "Reader.h"

Pixels* pixels = new Pixels(12, 8);
Reader* reader = new Reader(10, 9);
String uid = String("");

void setup() {
	pixels->setup();
	pixels->setIncrementAmount(10);
	pixels->setDelay(10);

	reader->setup();

	//Sets up timer0
	OCR0A = 0xAF;
	TIMSK0 |= _BV(OCIE0A);
}

void loop() {
	reader->scanForCards(uid);
}

SIGNAL(TIMER0_COMPA_vect) {
	pixels->displayPixels(millis());
}
