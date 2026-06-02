#include <Arduino.h>
#include <Servo.h>
#include "Config.h"
#include "Servos.h"

// Variables privadas del módulo
static Servo servo1, servo2, servo3, servo4;

void inicializarServos() {
    servo1.attach(PIN_SERVO_1);
    servo2.attach(PIN_SERVO_2);
    servo3.attach(PIN_SERVO_3);
    servo4.attach(PIN_SERVO_4);
    moverServos(90, 90, 90, 90); // Posición inicial centro
}

void moverServo(int numero, int angulo) {
    angulo = constrain(angulo, 0, 180);
    switch (numero) {
        case 1: servo1.write(angulo); break;
        case 2: servo2.write(angulo); break;
        case 3: servo3.write(angulo); break;
        case 4: servo4.write(angulo); break;
    }
}

void moverServos(int a1, int a2, int a3, int a4) {
    moverServo(1, a1);
    moverServo(2, a2);
    moverServo(3, a3);
    moverServo(4, a4);
}