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
  if(this->direction == 1){
    this->red += this->increment;
    this->green += this->increment;
    this->blue += this->increment;

    if(areLedsAtMax()){
      this->direction = -1;
    }
  }
  
  else if(this->direction == -1){
    this->red -= this->increment;
    this->green -= this->increment;
    this->blue -= this->increment;

    if(areLedsAtMin()){
      this->direction = 0;
    }
  }

  if(this->direction == 1 && (this->red == 170 || this->green == 170 || this->blue == 170)){
    this->next->setDirection(1);
  }
}

void Pixel::setNextPixel(Pixel* next){
  this->next = next;
}

void Pixel::setIncrementAmount(int increment){
  this->increment = increment;
}

bool Pixel::areLedsAtMax(){
  if(this->red >= 255 || this->green >= 255|| this->blue >= 255){
    this->red = 255;
    this->green = 255;
    this->blue = 255;
    return true;
  }
  return false;
}

bool Pixel::areLedsAtMin(){
  if(this->red <= 0 || this->green <= 0|| this->blue <= 0){
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    return true;
  }
  return false;
}
