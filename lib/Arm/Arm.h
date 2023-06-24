#ifndef ARM_H
#define ARM_H

#include "Motor.h"

class Arm {
private:
  Motor motors[6]; // Array de motores

public:
  /**
   * @brief Construtor da classe Arm e inicializa os motores do braço.
   * 
   */
  Arm();

  /**
   * @brief Leva os motores do braço à posição inicial.
   */
  void home();

  /**
   * @brief Define a posição individualmente para um motor específico.
   *
   * @param motorNum O número do motor (0 a 5).
   * @param position A posição desejada para o motor.
   */
  void setIndividualPosition(uint8_t motorNum, uint8_t position);

  /**
   * @brief Define a posição para cada motor do braço separadamente.
   *
   * @param position0 A posição desejada para o Motor 0.
   * @param position1 A posição desejada para o Motor 1.
   * @param position2 A posição desejada para o Motor 2.
   * @param position3 A posição desejada para o Motor 3.
   * @param position4 A posição desejada para o Motor 4.
   * @param position5 A posição desejada para o Motor 5.
   */
  void setArmPosition(uint8_t position0, uint8_t position1, uint8_t position2, uint8_t position3, uint8_t position4, uint8_t position5);

  /**
   * @brief Define a posição para cada motor do braço usando um vetor de posições.
   *
   * @param positions Um vetor contendo as posições desejadas para cada motor do braço.
   *                  O vetor deve ter 6 elementos.
   */
  void setPosition(const uint8_t positions[]);
};

#endif
