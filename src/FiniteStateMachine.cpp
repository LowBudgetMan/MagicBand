#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine(int pixNum, int pixPin, int sdaPin, int rstPin){
  this->pixels = new Pixels(pixNum, pixPin);
  this->reader = new Reader(sdaPin, rstPin);
  this->uid = String("");
}

void FiniteStateMachine::setup(){
  this->pixels->setup();
	this->reader->setup();
}

void FiniteStateMachine::stateSwitch(){
  switch (this->state) {
		case 0:
			this->idleSetup();
	    break;
	  case 1:
			this->idle();
	    break;
	  default:
	    this->idleSetup();
	  break;
	}
}

void FiniteStateMachine::displayPixels(){
  this->pixels->displayPixels(millis());
}

void FiniteStateMachine::idleSetup(){
	this->pixels->setIncrementAmount(10);
	this->pixels->setDelay(10);
	this->state = 1;
}

void FiniteStateMachine::idle(){
	this->reader->scanForCards(this->uid);
	if(this->uid != ""){
		Serial.println(this->uid);
		this->uid = "";
	}
}
