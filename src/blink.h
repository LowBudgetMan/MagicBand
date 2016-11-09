#include <Arduino.h>

class Blink{

  public:
    Blink(int delay);

    void blink();
    void setPin(int pin);

  private:
    void on();
    void off();

    int wait;
    int pin;
};
