#include <Arduino.h>
#include <SevSeg.h>

SevSeg sevseg;

void setup() {
  // display settings
  byte numDigits = 4;
  byte digitPins[] = {22, 23, 24, 25};
  byte segmentPins[] = {30, 31, 32, 33, 34, 35, 36, 37};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, false, false, false, false);
  sevseg.setBrightness(90);
}

void loop() {
  // display
  sevseg.setNumber(1234, 1);
  sevseg.refreshDisplay();
}