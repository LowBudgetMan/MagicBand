#include "Pixels.h"

Pixels::Pixels(int size, int pin){
  this->neoPixels = new Adafruit_NeoPixel(size, pin, NEO_GRB + NEO_KHZ800);
  this->pixels = new Pixel[size];
  this->size = size-1;
  this->setupPixels();
}

void Pixels::setup(){
  pinMode(3, INPUT);
  this->neoPixels->begin();
  this->neoPixels->show();
}

void Pixels::setupPixels(){
  for(int i = 0; i <= this->size; i++){
    this->pixels[i] = Pixel();
    this->pixels[i].setLocation(i);
    this->pixels[i].setNeoPixel(this->neoPixels);
    if(i != 0){
      this->pixels[i].setNextPixel(&this->pixels[i-1]);
    }
  }
  this->pixels[0].setNextPixel(&this->pixels[this->size]);
  this->pixels[0].setDirection(1);
}

void Pixels::displayPixels(long currentTime){
  if(currentTime - this->previousTime >= this->delay){
    for(int i = this->size; i >= 0; i--){
      this->pixels[i].animateWheel();
    }
    this->neoPixels->show();
    this->previousTime = currentTime;
  }
}

void Pixels::reset(){
  for(int i = this->size; i >= 0; i--){
    this->pixels[i].setColor(0,0,0);
    this->pixels[i].animateWheel();
  }
  this->neoPixels->show();
}

void Pixels::setIncrementAmount(int increment){
  for(int i = 0; i <= this->size; i++){
    this->pixels[i].setIncrementAmount(increment);
  }
}

void Pixels::setDelay(long delay){
  this->delay = delay;
}
