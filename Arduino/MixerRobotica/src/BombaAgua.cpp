#include <Arduino.h>
#include "Config.h"
#include "BombaAgua.h"

// Variables privadas del módulo


void inicializarBombas() {
    pinMode(PIN_BOMBA_1, OUTPUT);
    pinMode(PIN_BOMBA_2, OUTPUT);
    pinMode(PIN_BOMBA_3, OUTPUT);
    pinMode(PIN_BOMBA_4, OUTPUT);

    apagarAllBombas(); // Posición inicial apagando las bombas
}

void encenderApagarBombas(int bomba1 , int bomba2, int bomba3, int bomba4) {
    digitalWrite(PIN_BOMBA_1, bomba1);
    digitalWrite(PIN_BOMBA_2, bomba2);
    digitalWrite(PIN_BOMBA_3, bomba3);
    digitalWrite(PIN_BOMBA_4, bomba4);
}



void apagarAllBombas() {
    encenderApagarBombas(LOW, LOW, LOW, LOW);
}
