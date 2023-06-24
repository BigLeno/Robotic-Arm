/**
 * @file Motor.cpp
 */

#include "Motor.h"

Motor::Motor(uint8_t num, uint16_t minPulse, uint16_t maxPulse) {
  this->motorNum = num;
  this->minPulse = minPulse;
  this->maxPulse = maxPulse;
  this->currentPosition = 0;
  Serial.begin(115200);
}

void Motor::attach() {
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);
}

int Motor::conversor(int grau) {
  return (grau * (maxPulse - minPulse) / 180) + minPulse;
}

uint8_t Motor::getPosition() {
  return currentPosition;
}

void Motor::setPosition(uint8_t position) {
  currentPosition = position;
  pwm.setPWM(motorNum, 0, conversor(position));
}

void Motor::setPositionSmooth(uint8_t targetPosition, uint8_t increment) {
  uint8_t currentPosition = getPosition();
  if (currentPosition < targetPosition) {
    for (uint8_t pos = currentPosition; pos <= targetPosition; pos += increment) {
      pwm.setPWM(motorNum, 0, conversor(pos));
      delay(10); // Adiciona um atraso de 10 milissegundos entre os incrementos
    }
  } else {
    for (uint8_t pos = currentPosition; pos >= targetPosition; pos -= increment) {
      pwm.setPWM(motorNum, 0, conversor(pos));
      delay(10); // Adiciona um atraso de 10 milissegundos entre os incrementos
    }
  }
}