#ifndef L298MotorDriver_h
#define L298MotorDriver_h

#include "Arduino.h"
#include "L298Motor.h"

class L298MotorDriver {
public:
  L298MotorDriver(int pinI1, int pinI2, int pinEA, int pinI3, int pinI4, int pinEB);
  void setLeftMotor(int pwm);
  void setRightMotor(int pwm);
  void setBrake();
private:
  L298Motor *_motorA;
  L298Motor *_motorB;
};

#endif
