#ifndef L298Motor_h
#define L298Motor_h

#include "Arduino.h"

#define PWM_MIN 0
#define PWM_MAX 255
#define DELAY 100
#define RATE 2

class L298Motor {
  public:
    L298Motor(int pin1, int pin2, int pinE);
    virtual void changeSpeed(int speed);
    void setBrake();
    void releaseBrake();
    void setReverse(bool reverse);
  private:
    int _pin1;
    int _pin2;
    int _pinE;
    int _speed;
    bool _reverse;
    void changeDirection(int speed);
    void setSpeed(int speed);
    void moveForward();
    void moveBackward();
};

#endif
