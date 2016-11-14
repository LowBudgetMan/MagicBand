#include <Arduino.h>
#include <NeoPixel.h>
#include "Pixels.h"
#include "Reader.h"

Pixels* pixels = new Pixels(12, 8);
Reader* reader = new Reader(10, 9);
String uid = String("");

void setup() {
	pixels->setup();
	pixels->setIncrementAmount(10);
	pixels->setDelay(10);

	reader->setup();
}

void loop() {
	reader->scanForCards(uid);
	pixels->displayPixels();
}

// #include <SPI.h>
// #include <MFRC522.h>
// #include <NeoPixel.h>
//
// #define RINGPIN 8
// #define NUMPIXELS 12
//
// #define RST_PIN         9          //9 Configurable, see typical pin layout above
// #define SS_PIN          10         //10 Configurable, see typical pin layout above
//
// #define Idle            0
// #define Checking        1
// #define Good            2
// #define Bad             3
//
// #define Red             0
// #define Green           1
//
// Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, RINGPIN, NEO_GRB + NEO_KHZ800);
// long delayval = 100; // delay for half a second
// unsigned long previousMillis = 0;
// int ledNum = NUMPIXELS-1;
// int state = Idle;
// int timeout = 500;
// int colorlevel = 0;
//
// MFRC522* mfrc522 = new MFRC522(SS_PIN, RST_PIN);  // Create MFRC522 instance
//
// void setup() {
//   pixels.begin();
//   Serial.begin(9600);   // Initialize serial communications with the PC
//   while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
//   SPI.begin();      // Init SPI bus
//   mfrc522->PCD_Init();   // Init MFRC522
//   //mfrc522->PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
//   //Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
// }
//
// void colorFade(int color){
//   int r = 0;
//   int g = 0;
//   int b = 0;
//
//   if(colorlevel <= 255){
//     if(color == Red){
//       r = colorlevel;
//     }
//     else if(color == Green){
//       g = colorlevel;
//     }
//     for(int i = 0; i < NUMPIXELS; i++){
//       pixels.setPixelColor(i, pixels.Color(r,g,b));
//     }
//     pixels.show();
//     colorlevel+=5;
//     ledNum = NUMPIXELS - 1;
//   }
//   else{
//     if(ledNum != -1){
//       delayval = 50;
//       pixels.setPixelColor(ledNum, pixels.Color(0,0,0));
//       pixels.show();
//       ledNum-=1;
//     }
//     else{
//       ledNum = 0;
//       state = Idle;
//       delayval = 100;
//       colorlevel = 0;
//     }
//   }
// }
//
// void ringIdle(){
//   int n = 0;
//   int m = 0;
//   if(ledNum == NUMPIXELS-1){
//     n = 0;
//     m = 1;
//   }
//   else if(ledNum == NUMPIXELS - 2){
//     n = NUMPIXELS - 1;
//     m = 0;
//   }
//   else{
//     n = ledNum+1;
//     m = ledNum+2;
//   }
//   pixels.setPixelColor(ledNum, pixels.Color(255,255,255));
//   pixels.setPixelColor(n, pixels.Color(125,125,125));
//   pixels.setPixelColor(m, pixels.Color(0,0,0));
//   pixels.show(); // This sends the updated pixel color to the hardware.
//
//   if(ledNum == 0){
//     ledNum = NUMPIXELS - 1;
//   }
//   else{
//     ledNum=ledNum-1;
//   }
// }
//
// void checking(){
//   if(delayval > 30){
//     delayval -= 10;
//   }
//   ringIdle();
//   if(timeout > 0){
//     timeout = timeout - 1;
//     //Serial.println(timeout);
//   }
//   else{
//     timeout = 500;
//     state = Idle;
//     delayval = 100;
//   }
// }
//
// void loop() {
//   unsigned long currentMillis = millis();
//   if(currentMillis - previousMillis >= delayval){
//     if(state == Idle){
//       ringIdle();
//     }
//     if(state == Checking){
//       checking();
//     }
//     if(state == Good){
//       colorFade(Green);
//     }
//     if(state == Bad){
//       colorFade(Red);
//     }
//     previousMillis = currentMillis;
//   }
//
//   if(state == Idle){
//     // Look for new cards
//     if ( ! mfrc522->PICC_IsNewCardPresent()) {
//       return;
//     }
//
//     // Select one of the cards
//     if ( ! mfrc522->PICC_ReadCardSerial()) {
//       return;
//     }
//
//     //Serial.print(F("Card UID: "));
//     for (byte i = 0; i < mfrc522->uid.size; i++){
//       if(mfrc522->uid.uidByte[i] < 0x10)
//         Serial.print(F("0"));
//       Serial.print(mfrc522->uid.uidByte[i], HEX);
//     }
//     Serial.println();
//     mfrc522->PICC_HaltA();
//     state = Checking;
//   }
// }
//
// void serialEvent(){
//   while(Serial.available() > 0){
//     char inChar = (char)Serial.read();
//     if(state == Checking){
//       if(inChar == 'y'){
//         state = Good;
//         delayval = 20;
//       }
//       if(inChar == 'n'){
//         state = Bad;
//         delayval = 20;
//       }
//     }
//   }
// }
