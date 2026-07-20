#ifndef _VENTA_H
#define _VENTA_H

#include "Componente.h"

using namespace System;

namespace ModelMixer {
    [Serializable]
    public ref class Venta {
    public:
        property int id;
        property String^ nombreBebida;
        property int cantidad;
        property double coste;
        property DateTime^ fecha;

    public:
        Venta(int id, String^ nombreBebida, int cantidad, double coste, DateTime^ fecha) {
            this->id = id;
            this->nombreBebida = nombreBebida;
            this->cantidad = cantidad;
            this->coste = coste;
            this->fecha = fecha;
        };

        Venta(int id, String^ nombreBebida, int cantidad, double coste) {
            this->id = id;
            this->nombreBebida = nombreBebida;
            this->cantidad = cantidad;
            this->coste = coste;

        };
    };
}

#endif