#include <Arduino.h>
#include <SevSeg.h>

SevSeg sevseg;

const int PIN_BTN_START = 2;
const int PIN_BTN_RESET = 3;

bool lastStartBtnState = LOW;
bool lastResetBtnState = LOW;

// timer value
float timerMillis = 0;
// start or restart time
unsigned startMillis;

// state machine
enum StateMachine {
  IDLE,
  STUDY,
  BREAK,
  PAUSE
};
StateMachine state;

void setup() {
  // start serial communication
  Serial.begin(9600);

  // button settings
  pinMode(PIN_BTN_START, INPUT_PULLUP);
  pinMode(PIN_BTN_RESET, INPUT_PULLUP);

  // display settings
  byte numDigits = 4;
  byte digitPins[] = {22, 23, 24, 25};
  byte segmentPins[] = {30, 31, 32, 33, 34, 35, 36, 37};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, false, false, false, false);
  sevseg.setBrightness(90);

  // set the initial state to IDLE
  state = IDLE;

  // set 25 min timer
  timerMillis = 25 * 60 * 1000;
}

void loop() {

  switch (state) {
    case IDLE:
      
  }

  // display
  sevseg.setNumber(0000);
  sevseg.refreshDisplay();
}

bool isStartButtonPressed() {
  bool isPressed = false;
  // checking start button
  if (digitalRead(PIN_BTN_START) == LOW && lastStartBtnState == HIGH) {
    isPressed = true;
  }
  lastStartBtnState = digitalRead(PIN_BTN_START);

  return isPressed;
}

bool isRestartButtonPressed() {
  bool isPressed = false;
  // checking reset button
  if (digitalRead(PIN_BTN_RESET) == LOW && lastResetBtnState == HIGH) {
    isPressed = true;
  }
  lastResetBtnState = digitalRead(PIN_BTN_RESET);

  return isPressed;
}