#include "Arm.h"

Arm::Arm() : motors{
  Motor(0, 150, 600), // Motor 0
  Motor(1, 150, 600), // Motor 1
  Motor(2, 150, 600), // Motor 2
  Motor(3, 150, 600), // Motor 3
  Motor(4, 150, 600), // Motor 4
  Motor(5, 150, 600)  // Motor 5
} {
  for (int i = 0; i < 6; i++) {
    motors[i].attach();
  }

  Serial.begin(115200);
}

void Arm::home() {
  setIndividualPosition(0, 25); // Motor 0 - posição inicial específica
  setIndividualPosition(1, 55); // Motor 1 - posição inicial específica
  setIndividualPosition(2, 55); // Motor 2 - posição inicial específica
  setIndividualPosition(3, 50); // Motor 3 - posição inicial específica
  setIndividualPosition(4, 0); // Motor 4 - posição inicial específica
  setIndividualPosition(5, 0); // Motor 5 - posição inicial específica
}



void Arm::setIndividualPosition(uint8_t motorNum, uint8_t position) {
  if (motorNum < 6) {
    motors[motorNum].setPosition(position);
    Serial.print("Motor ");
    Serial.print(motorNum);
    Serial.print(" set to position ");
    Serial.println(position);
  }
}

void Arm::setArmPosition(uint8_t position0, uint8_t position1, uint8_t position2, uint8_t position3, uint8_t position4, uint8_t position5) {
  setIndividualPosition(0, position0); // Motor 0 - define a posição individualmente
  setIndividualPosition(1, position1); // Motor 1 - define a posição individualmente
  setIndividualPosition(2, position2); // Motor 2 - define a posição individualmente
  setIndividualPosition(3, position3); // Motor 3 - define a posição individualmente
  setIndividualPosition(4, position4); // Motor 4 - define a posição individualmente
  setIndividualPosition(5, position5); // Motor 5 - define a posição individualmente
}


void Arm::setPosition(const uint8_t positions[]) {
  for (int i = 0; i < 6; i++) {
    setIndividualPosition(i, positions[i]);
  }
}

