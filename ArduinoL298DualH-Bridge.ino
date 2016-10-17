#include "L298MotorDriver.h"

L298MotorDriver l298(8, 9, 10, 13, 12, 11);

void setup() {
  Serial.begin(115200);
}

void loop() {
//  for (int y = 1095; y <= 1895; y++) {
//    l298.changeVector(1485, y);
//  }
//  l298.setBrake();
//  delay(3000);
//  for (int y = 1095, x = 1087; y <= 1895, x <= 1886; y++, x++) {
//    l298.changeVector(x, y);
//  }
//  l298.setBrake();
//  delay(3000);
  for (int y = 1095; y <= 1895; y++) {
    for (int x = 1087; x <= 1886; x++) {
      l298.changeVector(x, y);
    }
  }
  l298.setBrake();
  delay(3000);
}


