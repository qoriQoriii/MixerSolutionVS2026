#include "pch.h"
#include "Venta.h"

// Implementación llamando al constructor base Componente(id, nombre, estado)
ModelMixer::Venta::Venta(int id, System::String^ nombreBebida, int cantidad, double coste, System::String^ fecha)
    : Componente(id, nombreBebida, L"COMPLETA") {
    this->cantidadBebidas = cantidad;
    this->costeTotal = coste;
    this->fechaVenta = fecha;
}


