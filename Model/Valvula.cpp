#include "pch.h"
#include "Valvula.h"
ModelMixer::Valvula::Valvula(int id, String^ nombre, String^ estado, double flujo, double tiempo)
    : Actuadores(id, nombre, estado) {
    this->flujo = flujo;
    this->tiempoApertura = tiempo;
}

