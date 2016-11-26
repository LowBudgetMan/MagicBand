#include <Arduino.h>
#include "FiniteStateMachine.h"

FiniteStateMachine* fsm = new FiniteStateMachine(12,8,10,9);

void setup() {
	fsm->setup();

	//Sets up timer0
	OCR0A = 0xAF;
	TIMSK0 |= _BV(OCIE0A);
}

void loop() {
	fsm->stateSwitch();
}

SIGNAL(TIMER0_COMPA_vect) {
	fsm->displayPixels();
}
