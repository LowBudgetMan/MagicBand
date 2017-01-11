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

void Pixels::setColor(int red, int green, int blue){
  for(int i = 0; i <= this->size; i++){
    this->pixels[i].setColor(red, green, blue);
  }
  this->neoPixels->show();
}

bool Pixels::fadeIn(long currentTime){
  if(currentTime - this->previousTime >= this->delay){
    this->previousTime = currentTime;

    bool allOn = true;
    for(int i = 0; i <= this->size; i++){
      if(!this->pixels[i].areLedsAtMax()){
        this->pixels[i].animateFadeIn();
        allOn = false;
      }
    }
    this->neoPixels->show();

    if(allOn){
      return true;
    }
  }
  return false;
}

void Pixels::setFirstPixelDirection(int state){
  this->pixels[0].setDirection(state);
}

void Pixels::resetPixelState(){
  for(int i = 0; i <= this->size; i++){
    this->pixels[i].setDirection(0);
  }
}

bool Pixels::spinOut(long currentTime){
  if(currentTime - this->previousTime >= this->delay){
    this->previousTime = currentTime;

    bool allOff = true;
    for(int i = 0; i <= this->size; i++){
      if(!this->pixels[i].areLedsAtMin()){
        this->pixels[i].animateSpinOut();
        allOff = false;
      }
    }
    this->neoPixels->show();

    if(allOff){
      return true;
    }
  }
  return false;
}
