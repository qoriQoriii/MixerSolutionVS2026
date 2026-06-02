#include "pch.h"
#include "Bebida.h"
ModelMixer::Bebida::Bebida(int id, String^ nombre, int precio, List<Insumo^>^ receta) {
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->receta = receta;
}