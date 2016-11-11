#include <Arduino.h>
#include <NeoPixel.h>
#include "Pixels.h"

Pixels* pixels = new Pixels(12, 12);

void setup() {
	pinMode(3, INPUT);
	pixels->setup();
	pixels->setIncrementAmount(10);
	pixels->setDelay(10);
}

void loop() {
	pixels->displayPixels();
}
