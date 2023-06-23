/**
 * @file Motor.cpp
 */

#include "Motor.h"

Motor::Motor(uint8_t num, uint16_t minPulse, uint16_t maxPulse) {
  this->motorNum = num;
  this->minPulse = minPulse;
  this->maxPulse = maxPulse;
}

void Motor::attach() {
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);
}

int Motor::conversor(int grau) {
  return (grau * (maxPulse - minPulse) / 180) + minPulse;
}

void Motor::setPosition(uint8_t position) {
  pwm.setPWM(motorNum, 0, conversor(position));
}
