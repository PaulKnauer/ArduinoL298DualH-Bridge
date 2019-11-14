#include "L298MotorDriver.h"

#include "Arduino.h"

/* Contructs a new L298MotorDriver to the assigned pins for motor A and B */
L298MotorDriver::L298MotorDriver(int pinI1, int pinI2, int pinEA, int pinI3, int pinI4, int pinEB) {
  _motorA = new L298Motor(pinI1, pinI2, pinEA);
  _motorB = new L298Motor(pinI3, pinI4, pinEB);
  _motorB->setReverse(true);
}

/* Sets the PWM of the left motor */
void L298MotorDriver::setLeftMotor(int pwm) {
  _motorA->changeSpeed(pwm);
}

/* Sets the PWM of the right motor */
void L298MotorDriver::setRightMotor(int pwm) {
  _motorB->changeSpeed(pwm);
}

/* Causes both A and B motors to brake */
void L298MotorDriver::setBrake() {
  _motorA->setBrake();
  _motorB->setBrake();
}
