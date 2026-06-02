#include "pch.h"
#include "Sensor.h"
ModelMixer::Sensor::Sensor(int id, String^ nombre, String^ estado, double litrado)
    : Componente(id, nombre, estado) {
    this->litrado = litrado;
}