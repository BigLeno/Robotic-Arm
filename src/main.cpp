#include <Arduino.h>
#include "Arm.h"

Arm arm;

/**
 * Inicializa a comunicação serial e configura os motores do braço.
 */
void setup() {
  Serial.begin(9600);
}

/**
 * Controla os motores do braço.
 */
void loop() {
  if (Serial.available()) {
    // Aguarda a entrada de um número no formato "motorNum,position"
    String input = Serial.readStringUntil('\n');
    int motorNum = input.substring(0, input.indexOf(',')).toInt();
    int position = input.substring(input.indexOf(',') + 1).toInt();

    arm.setIndividualPosition(motorNum, position);
  }
}
