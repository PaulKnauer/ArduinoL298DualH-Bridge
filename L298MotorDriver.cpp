#include "L298MotorDriver.h"

#include "Arduino.h"

/* Contructs a new L298MotorDriver to the assigned pins for motor A and B */
L298MotorDriver::L298MotorDriver(int pinI1, int pinI2, int pinEA, int pinI3, int pinI4, int pinEB) {
  _motorA = new L298Motor(pinI1, pinI2, pinEA);
  _motorB = new L298Motor(pinI3, pinI4, pinEB);
  _motorB->setReverse(true);
}

/* Used to mix both the steering and the speed of both Motor A and B */
void L298MotorDriver::changeVector(int x, int y) {
  int _x = map(x, 1087, 1895, -255, 255);
  int _y = map(y, 1087, 1895, -255, 255);
  _motorA->changeSpeed(_x + _y);
  _motorB->changeSpeed(_x - _y);
}

/* Causes both A and B motors to brake */
void L298MotorDriver::setBrake() {
  _motorA->setBrake();
  _motorB->setBrake();
}

