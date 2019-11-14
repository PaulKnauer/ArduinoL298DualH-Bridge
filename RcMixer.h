#ifndef RcMixer_h
#define RcMixer_h

#include "Arduino.h"

#define CH_1_PIN 10
#define CH_2_PIN 11

#define DEADZONE 20

class RcMixer {
public:
  RcMixer(int ch1_pin, int ch2_pin);
  void setPulse();
  int getLeftPWM();
  int getRightPWM();
private:
  int pulseToPWM(int pulse);
  int _x;
  int _y;
  int _ch1_pin;
  int _ch2_pin;
};

#endif
