#include <Arduino.h>
#include <NeoPixel.h>

class Pixel{
  public:
    Pixel(int red = 0, int blue = 0, int green = 0);

    void colorPixel(Adafruit_NeoPixel* neopixel, int location);
    void setColor(int red, int green, int blue);
    void setDirection(int direction);
    void animate();
    void setNextPixel(Pixel* next);
    void setIncrementAmount(int increment);
    bool areLedsAtMax();
    bool areLedsAtMin();

  private:

    Pixel* next = NULL;
    int red = 0;
    int green = 0;
    int blue = 0;
    int direction = 0;
    int increment = 1;
};
