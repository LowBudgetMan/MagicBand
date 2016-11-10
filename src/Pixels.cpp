#include "Pixels.h"

Pixels::Pixels(int size, int pin){
  this->neoPixels = new Adafruit_NeoPixel(size, pin, NEO_GRB + NEO_KHZ800);
  this->pixels = new Pixel[size];
  this->size = size-1;
  this->setupPixels();
}

void Pixels::setup(){
  this->neoPixels->begin();
  this->neoPixels->show();
}

void Pixels::setupPixels(){
  for(int i = 0; i <= this->size; i++){
    this->pixels[i] = Pixel();
    if(i != 0){
      this->pixels[i].setNextPixel(&this->pixels[i-1]);
    }
  }
  this->pixels[0].setNextPixel(&this->pixels[this->size]);
  this->pixels[0].setDirection(1);
}

void Pixels::displayPixels(){
  for(int i = this->size; i >= 0; i--){
    this->pixels[i].colorPixel(this->neoPixels, i);
  }

  this->neoPixels->show();
}

void Pixels::reset(){
  for(int i = this->size; i >= 0; i--){
    this->pixels[i].setColor(0,0,0);
    this->pixels[i].colorPixel(this->neoPixels, i);
  }
  this->neoPixels->show();
}
