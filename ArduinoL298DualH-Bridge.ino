#include "L298MotorDriver.h"
#include "RcMixer.h"

L298MotorDriver l298(8, 9, 10, 13, 12, 11);
RcMixer mixer(4, 7);

void setup() {
  Serial.begin(115200);
}

void loop() {
  mixer.setPulse();
  int left = mixer.getLeftPWM();
  int right = mixer.getRightPWM();

  l298.setLeftMotor(left);
  l298.setRightMotor(right);
}
