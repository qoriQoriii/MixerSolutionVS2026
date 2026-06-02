#include "pch.h"
#include "Tanque.h"
ModelMixer::Tanque::Tanque(int id, String^ nombre, String^ estado, Insumo^ insumo, double nivel)
    : Componente(id, nombre, estado) {
    this->insumo = insumo;
    this->nivelAgua = nivel;
}