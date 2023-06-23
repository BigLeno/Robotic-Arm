#include <Arduino.h>
#include "Arm.h"

Arm arm;

/**
 * Inicializa a comunicação serial e configura os motores do braço.
 */
void setup() {
  Serial.begin(115200);
}

/**
 * Controla os motores do braço.
 */
void loop() {
  if (Serial.available()) {
    // Aguarda a entrada de um comando no formato "motorNum,position" ou "home"
    String input = Serial.readStringUntil('\n');
    Serial.print(input);
    if (input == "home") {
      arm.home();
      Serial.println("Home command executed");
    } else {
      // Extrai o número do motor e a posição da string lida
      int motorNum = input.substring(0, input.indexOf(',')).toInt();
      int position = input.substring(input.indexOf(',') + 1).toInt();

      arm.setIndividualPosition(motorNum, position);
    }
  }
}

