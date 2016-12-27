#include "Memory.h"

void Memory::put(String uid){
  this->memory[this->location] = uid;
  this->location += 1;
}

bool Memory::check(String uid){
  for(int i = 0; i <= this->location; i++){
    if(this->memory[i] == uid){
      return true;
    }
  }
  return false;
}

void Memory::clear(){
  String copy[100] = {};
  memcpy( this->memory, copy, 1);
  delete copy;
  this->location = 0;
}
