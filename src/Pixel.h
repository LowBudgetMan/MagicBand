#include <Arduino.h>
#include <NeoPixel.h>

class Pixel{
  public:
    Pixel(int red = 0, int blue = 0, int green = 0);

    void animateWheel();
    void animateFadeIn();

    bool areLedsAtMax();
    bool areLedsAtMin();

    void setColor(int red, int green, int blue);
    void setDirection(int direction);
    void setNextPixel(Pixel* next);
    void setIncrementAmount(int increment);
    void setLocation(int location);
    void setNeoPixel(Adafruit_NeoPixel* neoPixel);


  private:
    void updateNeoPixel();

    Pixel* next = NULL;
    Adafruit_NeoPixel* neoPixel;
    int location;
    int red = 0;
    int green = 0;
    int blue = 0;
    int direction = 0;
    int increment = 1;
};
