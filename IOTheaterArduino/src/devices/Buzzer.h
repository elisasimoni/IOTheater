#ifndef BUZZER_H
#define BUZZER_H

#include "Sound.h"

class Buzzer : public Sound {
public:
  Buzzer(int pin);
  void switchOff();
  void playTone(int tone, int duration);
  void sound(int melody, int noteDurations, int pin);
  
protected:
  int buzzerPin;
};

#endif
