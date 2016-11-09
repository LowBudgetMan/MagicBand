#include "Pixel.h"

Pixel::Pixel(int red, int green, int blue, int direction){
  this->red = red;
  this->green = green;
  this->blue = blue;
  this->direction = direction;
}

void Pixel::colorPixel(Adafruit_NeoPixel* neoPixel, int location){
  neoPixel->setPixelColor(location, neoPixel->Color(this->red,this->green,this->blue));
}

void Pixel::setColor(int red, int green, int blue){
  this->red = red;
  this->green = green;
  this->blue = blue;
}
