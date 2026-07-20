#ifndef _INSUMO_H
#define _INSUMO_H

#include "InsumoBebida.h"

using namespace System;

namespace ModelMixer {
    [Serializable]
    public ref class Insumo{
    public:
        property int id;
        property String^ nombre;
        property int stockActual;
        property int stockMinimoAlerta;

    public:
        Insumo(int id, String^ nombre, int stockActual, int stockMinimoAlerta) {
            this->id = id;
            this->nombre = nombre;
            this->stockActual = stockActual;
            this->stockMinimoAlerta = stockMinimoAlerta;
        };
    };
}

#endif