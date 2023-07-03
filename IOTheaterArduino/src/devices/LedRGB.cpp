#include "LedRGB.h"
#include <Arduino.h>

LedRGB::LedRGB(int pinR, int pinG, int pinB) {
  this->pinR = pinR;
  this->pinG = pinG;
  this->pinB = pinB;
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void LedRGB::setColor(int r, int g, int b) {
  analogWrite(pinR, r);
  analogWrite(pinG, g);
  analogWrite(pinB, b);
}

void LedRGB::switchOff() {
  setColor(0, 0, 0);
}






