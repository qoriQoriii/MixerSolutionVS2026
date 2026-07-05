#pragma once
#ifndef _VENTA_H
#define _VENTA_H
#include "Componente.h"

namespace ModelMixer {
    [Serializable]
    public ref class Venta : public Componente {
    public:
        int cantidadBebidas;
        double costeTotal;
        System::String^ fechaVenta;

        // Constructor adaptado idéntico a Actuadores
        Venta(int id, System::String^ nombreBebida, int cantidad, double coste, System::String^ fecha);
    };
}
#endif