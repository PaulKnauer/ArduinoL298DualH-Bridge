#include "L298Motor.h"

#include "Arduino.h"

/* Constructs a L298Motor to the assigned pins */
L298Motor::L298Motor(int pin1, int pin2, int pinE) {
  _pin1 = pin1;
  _pin2 = pin2;
  _pinE = pinE;
  pinMode(_pin1, OUTPUT);
  pinMode(_pin2, OUTPUT);
  pinMode(_pinE, OUTPUT);
  _speed = 0;
}

/* Used to gracefully change the speed and direction of the motor */
void L298Motor::changeSpeed(int speed) {
  changeDirection(speed);
  setSpeed(speed);
}

/* Causes the motor to regeneratively brake */
void L298Motor::setBrake() {
  digitalWrite(_pin1, HIGH);
  digitalWrite(_pin2, HIGH);
}

/* Removes power from the motor */
void L298Motor::releaseBrake() {
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, LOW);
}

/* Reverses the direction of the motor if set */
void L298Motor::setReverse(bool reverse) {
  _reverse = reverse;
}

/* Private function */
void L298Motor::changeDirection(int speed) {
  if (speed > PWM_MIN) {
    if (_reverse) {
      moveForward();
    } else {
      moveBackward();
    }
  } else if (speed < PWM_MIN) {
    if (_reverse) {
      moveBackward();
    } else {
      moveForward();
    }
  }
}

/* Private function */
void L298Motor::setSpeed(int speed) {
  int absSpeed = abs(speed);
  analogWrite(_pinE, absSpeed);
  _speed = speed;
  delay(DELAY);
}

/* Private function */
void L298Motor::moveForward() {
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, HIGH);
}

/* Private function */
void L298Motor::moveBackward() {
  digitalWrite(_pin1, HIGH);
  digitalWrite(_pin2, LOW);
}
