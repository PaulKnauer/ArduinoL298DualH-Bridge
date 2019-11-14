#include "RcMixer.h"

RcMixer::RcMixer(int ch1_pin, int ch2_pin) {
  _ch1_pin = ch1_pin;
  _ch2_pin = ch2_pin;
  _x = 0;
  _y = 0;
}

/* set the pulse from both channels to be mixed */
void RcMixer::setPulse() {
  _x = pulseIn(_ch1_pin, HIGH, 25000);
  _x = pulseToPWM(_x);
  _y = pulseIn(_ch2_pin, HIGH, 25000);
  _y = pulseToPWM(_y);
}

/* Returns the mixed left PWM */
int RcMixer::getLeftPWM() {
  return _y + _x;
}

/* Returns the mixed right PWM */
int RcMixer::getRightPWM() {
  return _y - _x;
}

/* Private function */
int RcMixer::pulseToPWM(int pulse) {
  if (pulse > 1000) {
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -255, 255);
  } else {
    pulse = 0;
  }

  if (abs(pulse) <= DEADZONE) {
    pulse = 0;
  }

  return pulse;
}
