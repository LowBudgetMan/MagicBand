#include <Arduino.h>
#include <NeoPixel.h>
#include "Pixels.h"
#include "Reader.h"
#include "Memory.h"

class FiniteStateMachine{
  public:
    FiniteStateMachine(int pixNum, int pixPin, int sdaPin, int rstPin);
    void setup();
    void stateSwitch();
    void displayPixels();

  private:
    void idleSetup();
    void idle();
    void checkingSetup();
    void checking();
    void goodIdSetup();
    void badIdSetup();
    void fadeIn();

    Pixels* pixels;
    Reader* reader;
    Memory* memory;
    String uid;
    int state = 0;
};
