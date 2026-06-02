#include "pch.h"
#include "Componente.h"
ModelMixer::Componente::Componente(int id, String^ nombre, String^ estado) {
    this->id = id;
    this->nombre = nombre;
    this->estado = estado;
}