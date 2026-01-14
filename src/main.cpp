#include <Arduino.h>
#include <SevSeg.h>

SevSeg sevseg;

const int PIN_BTN_START = 2;
const int PTN_BTN_RESET = 3;

bool lastStartBtnState = LOW;

int count = 0;


void setup() {
  // start serial communication
  Serial.begin(9600);

  // button settings
  pinMode(PIN_BTN_START, INPUT_PULLUP);
  pinMode(PIN_BTN_START, INPUT_PULLUP);

  // display settings
  byte numDigits = 4;
  byte digitPins[] = {22, 23, 24, 25};
  byte segmentPins[] = {30, 31, 32, 33, 34, 35, 36, 37};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, false, false, false, false);
  sevseg.setBrightness(90);
}

void loop() {
  // display
  sevseg.setNumber(count);
  sevseg.refreshDisplay();

  // checking start button
  if (digitalRead(PIN_BTN_START) == LOW && lastStartBtnState == HIGH) {
    count++;
  }
  lastStartBtnState = digitalRead(PIN_BTN_START);
}