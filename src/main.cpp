#include <Arduino.h>
#include <SevSeg.h>

SevSeg sevseg;

const int PIN_BTN_START = 2;
const int PIN_BTN_RESET = 3;

bool lastStartBtnState = LOW;
bool lastResetBtnState = LOW;

unsigned long studyMillis = 15000;
unsigned long breakMillis = 3000; 

// timer value
long timerMillis;
// start or restart time
unsigned long startMillis;

// state machine
enum StateMachine {
  IDLE,
  STUDY,
  BREAK,
  PAUSE
};
StateMachine state;

// previous state
StateMachine prevState;

bool isStartButtonPressed();
bool isResetButtonPressed();

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
  timerMillis = studyMillis;
}

void loop() {

  switch (state) {
    case IDLE:
      if (isStartButtonPressed()) {
        // start timer
        state = STUDY;
        startMillis = millis();
      }
      break;
    case STUDY:
      timerMillis = studyMillis - millis() + startMillis;
      // when timer runs out
      if (timerMillis <= 0) {
        state = BREAK;
        startMillis = millis();
      }
      if (isStartButtonPressed()) {
        // pause timer
        state = PAUSE;
        prevState = STUDY;
      }
      break;
    case BREAK:
      timerMillis = breakMillis - millis() + startMillis;
      // when timer runs out
      if (timerMillis <= 0) {
        state = STUDY;
        startMillis = millis();
      }
      if (isStartButtonPressed()) {
        // pause timer
        state = PAUSE;
        prevState = BREAK;
      }
      break;
    case PAUSE:
      if (isStartButtonPressed()) {
        // restart timer
        if (prevState == STUDY) {
          state = STUDY;
          startMillis = millis() - studyMillis + timerMillis;
        }
        else {
          state = BREAK;
          startMillis = millis() - breakMillis + timerMillis;
        }
      }
      if (isResetButtonPressed()) {
        // reset timer
        state = IDLE;
        timerMillis = studyMillis;
      }
      break;
  }

  // keep minute under 100
  int minute = timerMillis / 1000 / 60 % 100;
  int second = timerMillis / 1000 % 60;
  int displayValue = minute * 100 + second;

  // display
  sevseg.setNumber(displayValue, 2);
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

bool isResetButtonPressed() {
  bool isPressed = false;
  // checking reset button
  if (digitalRead(PIN_BTN_RESET) == LOW && lastResetBtnState == HIGH) {
    isPressed = true;
  }
  lastResetBtnState = digitalRead(PIN_BTN_RESET);

  return isPressed;
}