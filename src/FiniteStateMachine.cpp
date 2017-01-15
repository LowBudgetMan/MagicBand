#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine(int pixNum, int pixPin, int sdaPin, int rstPin, int clearPin, int addPin){
  this->pixels = new Pixels(pixNum, pixPin);
  this->reader = new Reader(sdaPin, rstPin);
  this->memory = new Memory();
  this->uid = String("");
  this->addPin = 2;
  this->clearPin = 3;
}

void FiniteStateMachine::setup(){
  pinMode(2, INPUT);
  pinMode(3, INPUT);

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
    case 2:
      this->checkingSetup();
      break;
    case 3:
      this->checking();
      break;
    case 4:
      this->goodIdSetup();
      break;
    case 5:
      this->badIdSetup();
      break;
    case 6:
      this->fadeIn();
      break;
    case 7:
      this->spinOutSetup();
      break;
    case 8:
      this->spinOut();
      break;
    case 9:
      this->addIdle();
      break;
    case 10:
      this->addId();
      break;
    case 11:
      this->addedIdSetup();
      break;
    case 12:
      this->removeId();
      break;
	  default:
	    this->idleSetup();
	  break;
	}
}

void FiniteStateMachine::displayPixels(){
  if(this->state >= 4 && this->state <= 6){
    if(this->pixels->fadeIn(millis())){
        this->state = 7;
    }
  }
  else if(this->state >= 7 && this->state <= 8){
    if(this->pixels->spinOut(millis())){
        this->state = 0;
    }
  }
  else{
    this->pixels->displayPixels(millis());
  }
}

void FiniteStateMachine::idleSetup(){
  this->pixels->setColor(0,0,0);
	this->pixels->setIncrementAmount(10);
	this->pixels->setDelay(10);
  this->pixels->resetPixelState();
  this->pixels->setFirstPixelDirection(1);
  this->uid = "";
	this->state = 1;
}

void FiniteStateMachine::idle(){
	this->reader->scanForCards(this->uid);

  if(digitalRead(this->addPin) == LOW){
    this->state = 9;
    return;
  }

  if(digitalRead(this->clearPin) == LOW){
    this->state = 12;
    return;
  }

	if(this->uid != ""){
		Serial.println(this->uid);
    this->state = 2;
    return;
	}
}

long previous = 0;

void FiniteStateMachine::checkingSetup(){
	this->pixels->setIncrementAmount(10);
	this->pixels->setDelay(2);
	this->state = 3;
  previous = millis();
}

void FiniteStateMachine::checking(){
  if(this->memory->check(this->uid)){
      this->state = 4;
  }
  else{
    this->state = 5;
  }
  if(millis()-previous >= 5000){
    this->state = 0;
  }
}

void FiniteStateMachine::goodIdSetup(){
  this->pixels->setIncrementAmount(1);
  this->pixels->setDelay(5);
  this->pixels->setColor(0,1,0);
  this->state = 6;
}

void FiniteStateMachine::badIdSetup(){
  this->pixels->setIncrementAmount(1);
	this->pixels->setDelay(5);
  this->pixels->setColor(1,0,0);
  this->state = 6;
}

void FiniteStateMachine::fadeIn(){
}

void FiniteStateMachine::spinOutSetup(){
  this->pixels->setIncrementAmount(1);
  this->pixels->setDelay(2);
  this->pixels->resetPixelState();
  this->pixels->setFirstPixelDirection(-1);
  this->state = 8;
}

void FiniteStateMachine::spinOut(){
}

void FiniteStateMachine::addIdle(){
}

void FiniteStateMachine::addId(){
}

void FiniteStateMachine::addedIdSetup(){
}

void FiniteStateMachine::removeId(){
}
