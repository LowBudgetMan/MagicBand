#include <Arduino.h>
#include <NeoPixel.h>
#include "Pixels.h"

Pixels* pixels = new Pixels(12, 12);

void setup() {
	pinMode(3, INPUT);
	pixels->setup();
}

void loop() {
	pixels->displayPixels();
	delay(1000);
	pixels->reset();
}
