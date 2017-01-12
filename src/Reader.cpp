#include "Reader.h"

Reader::Reader(int sda, int reset){
  this->reader = new MFRC522(sda, reset);
}

void Reader::setup(){
  Serial.begin(9600);
  SPI.begin();
  this->reader->PCD_Init();
  // this->reader->PCD_SetRegisterBitMask(this->reader->RFCfgReg, (0x07<<4));
}

void Reader::scanForCards(String& uid){
  // Look for new cards
  if (!this->reader->PICC_IsNewCardPresent()){
    return;
  }

  // Select one of the cards
  if (!this->reader->PICC_ReadCardSerial()){
    return;
  }

  for (byte i = 0; i < this->reader->uid.size; i++){
    if(this->reader->uid.uidByte[i] < 0x10)
      uid += "0";
    uid += String(this->reader->uid.uidByte[i], HEX);
  }
  this->reader->PICC_HaltA();
}
