#include "Pixels.h"

Pixels::Pixels(int size, int pin){
  this->neoPixels = new Adafruit_NeoPixel(size, pin, NEO_GRB + NEO_KHZ800);
  this->pixels = new Pixel[size];
  this->size = size;
  this->setupPixels();
}

void Pixels::setup(){
  this->neoPixels->begin();
  this->neoPixels->show();
}

void Pixels::setupPixels(){
  int size = this->size - 1;
  this->pixels[size] = Pixel(60, 60, 60, -1); //60
  this->pixels[size-1] = Pixel(255, 255, 255, -1); //255
  this->pixels[size-2] = Pixel(60, 60, 60, 1); //60

  for(int i = size - 3; i >= 0; i--){
    this->pixels[i] = Pixel();
  }
}

void Pixels::displayPixels(){
  for(int i = this->size-1; i >= 0; i--){
    this->pixels[i].colorPixel(this->neoPixels, i);
  }

  this->neoPixels->show();
}

void Pixels::reset(){
  for(int i = this->size-1; i >= 0; i--){
    this->pixels[i].setColor(0,0,0);
    this->pixels[i].colorPixel(this->neoPixels, i);
  }
  this->neoPixels->show();
}
