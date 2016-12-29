#include <Arduino.h>
#include <NeoPixel.h>
#include "Pixel.h"

class Pixels {
  public:
    Pixels(int size, int pin);

    void displayPixels(long currentTime);
    bool fadeIn(long currentTime);
    void setup();
    void reset();
    void setIncrementAmount(int increment);
    void setDelay(long delay);
    void setColor(int red, int green, int blue);

  private:
    void setupPixels();

    Pixel* pixels;
    Adafruit_NeoPixel* neoPixels;
    int size;
    unsigned long previousTime = 0;
    long delay = 100;
};
