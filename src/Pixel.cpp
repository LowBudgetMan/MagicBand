#include "Pixel.h"

Pixel::Pixel(int red, int green, int blue){
  this->red = red;
  this->green = green;
  this->blue = blue;
}

void Pixel::updateNeoPixel(){
  this->neoPixel->setPixelColor(this->location, this->neoPixel->Color(this->red,this->green,this->blue));
}

void Pixel::animateWheel(){
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

  updateNeoPixel();
}

void Pixel::animateFadeIn(){
  if(this->red > 0 && this->red < 255){
    this->red += this->increment;
  }
  if(this->green > 0 && this->green < 255){
    this->green += this->increment;
  }
  if(this->blue > 0 && this->blue < 255){
    this->blue += this->increment;
  }
  updateNeoPixel();
}

void Pixel::animateSpinOut(){
  if(this->direction == -1){
    if(this->red > 0 && this->red <= 255){
      this->red -= this->increment;
    }
    if(this->green > 0 && this->green <= 255){
      this->green -= this->increment;
    }
    if(this->blue > 0 && this->blue <= 255){
      this->blue -= this->increment;
    }
  }

  if(this->direction == -1 && (this->red <= 200 && this->green <= 200 && this->blue <= 200)){
    this->next->setDirection(-1);
  }

  updateNeoPixel();
}

bool Pixel::areLedsAtMax(){
  bool atMax = false;
  if(this->red >= 255){
    this->red = 255;
    atMax = true;
  }
  if(this->green >= 255){
    this->green = 255;
    atMax = true;
  }
  if(this->blue >= 255){
    this->blue = 255;
    atMax = true;
  }
  return atMax;
}

bool Pixel::areLedsAtMin(){
  bool redMin = false;
  bool greenMin = false;
  bool blueMin = false;

  if(this->red <= 0){
    this->red = 0;
    redMin = true;
  }
  if(this->green <= 0){
    this->green = 0;
    greenMin = true;
  }
  if(this->blue <= 0){
    this->blue = 0;
    blueMin = true;
  }

  return (redMin && greenMin && blueMin);
}

void Pixel::setNextPixel(Pixel* next){
  this->next = next;
}

void Pixel::setIncrementAmount(int increment){
  this->increment = increment;
}

void Pixel::setLocation(int location){
  this->location = location;
}

void Pixel::setNeoPixel(Adafruit_NeoPixel* neoPixel){
  this->neoPixel = neoPixel;
}

void Pixel::setColor(int red, int green, int blue){
  this->red = red;
  this->green = green;
  this->blue = blue;
  updateNeoPixel();
}

void Pixel::setDirection(int direction){
  this->direction = direction;
}
