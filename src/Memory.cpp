#include "Memory.h"

Memory::Memory(){
}

void Memory::put(String uid){
  if(this->location <= 98){
    this->location += 1;
    this->memory[this->location] = uid;
  }
}

bool Memory::check(String uid){
  if(this->location == -1){
    return false;
  }
  for(int i = 0; i <= this->location; i++){
    if(this->memory[i].equals(uid)){
      // Serial.println("ARRAY VAL: " + this->memory[i]);
      // Serial.println("UID: " + uid);
      return true;
    }
  }
  return false;
}

void Memory::clear(){
  String copy[100] = {};
  memcpy( this->memory, copy, 1);
  delete copy;
  this->location = -1;
}
