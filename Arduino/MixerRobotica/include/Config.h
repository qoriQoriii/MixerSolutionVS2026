#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
// Pines — Servomotores
const int PIN_SERVO_1 = 8;
const int PIN_SERVO_2 = 9;
const int PIN_SERVO_3 = 10;
const int PIN_SERVO_4 = 11;

// Pines — HC-SR04 (Ultrasonido)
const int TRIG_1 = A0; const int ECHO_1 = A1;   
const int TRIG_2 = A2; const int ECHO_2 = A3;   
const int TRIG_3 =  5; const int ECHO_3 =  6;   
const int TRIG_4 =  2; const int ECHO_4 =  3;   

#define MAX_DISTANCE 200

// Pines — Motor DC (L298N)
const int MOTOR_IN1 = 12;   
const int MOTOR_IN2 =  7;

// Configuración de la Receta Dinámica
const int numeroIngredientes = 4;      // Cantidad de tanques/servos
const int delayServido = 3000;         // Tiempo que se quedan abiertos (3 segundos)

// Umbral del tanque. 
// NOTA: Si usas ultrasonido desde arriba, una distancia pequeña significa tanque LLENO.
// Si tu lógica requiere que la lectura sea MAYOR a este tope para pasar, ajusta este valor:
const int ReservaMinimaTanque = 10;    // Umbral de validación en cm
#endif