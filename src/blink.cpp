#include "blink.h"

Blink::Blink(int delay){
  this->wait = delay;
}

void Blink::on(){
  digitalWrite(this->pin, HIGH);
  delay(this->wait);
}

void Blink::off(){
  digitalWrite(this->pin, LOW);
  delay(this->wait);
}

void Blink::blink(){
  on();
  off();
}

void Blink::setPin(int pin){
  this->pin = pin;
  pinMode(pin, OUTPUT);
}
