#include <Arduino.h>
#include <NeoPixel.h>
#include "Pixels.h"
#include "Reader.h"

Pixels* pixels = new Pixels(12, 8);
Reader* reader = new Reader(10, 9);

void setup() {
	pixels->setup();
	pixels->setIncrementAmount(10);
	pixels->setDelay(10);

	reader->setup();
}

void loop() {
	pixels->displayPixels();
}
