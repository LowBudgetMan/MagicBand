#include <Arduino.h>
#include <NeoPixel.h>

class Pixel{
  public:
    Pixel(int red = 0, int blue = 0, int green = 0, int direction = 1);

    void colorPixel(Adafruit_NeoPixel* neopixel, int location);
    void setColor(int red, int green, int blue);

  private:
    int red;
    int green;
    int blue;
    int direction;
};
