#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
// Pines — Bombas de Agua
const int PIN_BOMBA_1 = 8;
const int PIN_BOMBA_2 = 9;
const int PIN_BOMBA_3 = 10;
const int PIN_BOMBA_4 = 11;

/*
// Pines — Servomotores
const int PIN_SERVO_1 = 8;
const int PIN_SERVO_2 = 9;
const int PIN_SERVO_3 = 10;
const int PIN_SERVO_4 = 11;
*/

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
const int numeroTanques = 4;      // Cantidad de tanques/servos
const int delayServido = 3000;         // Tiempo que se quedan abiertos (3 segundos)

// Umbral del tanque. 
const int LecturaMinimaTanqueDistancia = 2;    // Umbral de validación en cm
const int LecturaMaxTanqueDistancia = 11; 

// Comandos seriales reconocidos
enum ComandoSerial {
    CMD_PEDIDO,
    CMD_REPORTE_TANQUE,
    CMD_DESCONOCIDO
};

inline ComandoSerial parsearComando(const String& comando) {
    if (comando.startsWith("PEDIDO:"))  return CMD_PEDIDO;
    if (comando == "REPORTE_TANQUE")    return CMD_REPORTE_TANQUE;
    return CMD_DESCONOCIDO;
}

// CORRECCIÓN: Ahora es 'extern'. Prometemos al compilador que este arreglo existe,
// pero no ocupamos memoria aquí para que no se duplique en cada archivo .cpp
extern String reporteTanque[numeroTanques];

#endif