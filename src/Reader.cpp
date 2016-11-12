#include "Reader.h"

Reader::Reader(int sda, int reset){
  this->reader = new MFRC522(sda, reset);
}

void Reader::setup(){
  Serial.begin(9600);
  SPI.begin();
  this->reader->PCD_Init();
}
