#include <Arduino.h>
#include <NeoPixel.h>
#include "Pixel.h"

class Pixels {
  public:
    Pixels(int size, int pin);

    void displayPixels();
    void setup();
    void reset();

  private:
    void setupPixels();

    Pixel* pixels;
    Adafruit_NeoPixel* neoPixels;
    int size;
};
