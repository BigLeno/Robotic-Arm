/**
 * @file Motor.h
 */

#ifndef MOTOR_H
#define MOTOR_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

class Motor {
private:
  Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
  uint8_t motorNum;     // Número referente a cada motor
  uint16_t minPulse;    // Valor mínimo de pulso
  uint16_t maxPulse;    // Valor máximo de pulso

public:
  /**
   * @brief Construtor para a classe Motor.
   *
   * @param num       O número referente ao motor.
   * @param minPulse  O valor mínimo de pulso.
   * @param maxPulse  O valor máximo de pulso.
   */
  Motor(uint8_t num, uint16_t minPulse, uint16_t maxPulse);

  /**
   * @brief Inicializa o motor.
   */
  void attach();

  /**
   * @brief Converte graus para pulso.
   *
   * @param grau  O valor em graus.
   * @return      O valor de pulso convertido.
   */
  int conversor(int grau);

  /**
   * @brief Define a posição do motor.
   *
   * @param position  A posição em graus.
   */
  void setPosition(uint8_t position);
};

#endif
