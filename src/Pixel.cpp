#include "Pixel.h"

Pixel::Pixel(int red, int green, int blue){
  this->red = red;
  this->green = green;
  this->blue = blue;
}

void Pixel::colorPixel(Adafruit_NeoPixel* neoPixel, int location){
  animate();
  neoPixel->setPixelColor(location, neoPixel->Color(this->red,this->green,this->blue));
}

void Pixel::setColor(int red, int green, int blue){
  this->red = red;
  this->green = green;
  this->blue = blue;
}

void Pixel::setDirection(int direction){
  this->direction = direction;
}

void Pixel::animate(){
  if(this->direction == 1 && !areLedsAtMax()){
    this->red += 1;
    this->green += 1;
    this->blue += 1;
  }
  else if(this->direction == 1 && areLedsAtMax()){
    this->direction = -1;
  }
  else if(this->direction == -1 && !areLedsAtMin()){
    this->red -= 1;
    this->green -= 1;
    this->blue -= 1;
  }
  else if(this->direction == -1 && areLedsAtMin()){
    this->direction = 1;
  }

}

bool Pixel::areLedsAtMax(){
  if(this->red >= 255 || this->green >= 255|| this->blue >= 255){
    return true;
  }
  return false;
}

bool Pixel::areLedsAtMin(){
  if(this->red <= 0 || this->green <= 0|| this->blue <= 0){
    return true;
  }
  return false;
}
