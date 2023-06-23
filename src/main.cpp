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
  arm.setIndividualPosition(0, 90); // Define a posição do Motor 0 para 90 graus
}
