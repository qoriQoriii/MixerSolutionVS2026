#include "pch.h"
#include "Insumo.h"
ModelMixer::Insumo::Insumo(int id, String^ nombre, int stockActual, int stockMinimo):InsumoBebida(id,nombre) {
    this->id = id;
    this->nombre = nombre;
    this->stockActual = stockActual;
    this->stockMinimoAlerta = stockMinimo;
}