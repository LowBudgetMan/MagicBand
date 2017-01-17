#include <Arduino.h>
#include <EEPROM.h>

class Memory{
  public:
    Memory();
    void put(String uid);
    bool check(String uid);
    void clear();

  private:
    String memory[100] = {};
    int location = -1;
    int size = 68; //EEPROM can hold 68 IDs with NANO chip
};
