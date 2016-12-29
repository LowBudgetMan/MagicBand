#include <Arduino.h>

class Memory{
  public:
    Memory();
    void put(String uid);
    bool check(String uid);
    void clear();

  private:
    String memory[100] = {};
    int location = -1;
};
