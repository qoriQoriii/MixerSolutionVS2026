#ifndef _BEBIDA_H
#define _BEBIDA_H
#include "Insumo.h"
using namespace System;
using namespace System::Collections::Generic;

namespace ModelMixer {
    [Serializable]
    public ref class Bebida {
    public:
        property int id;
        property String^ nombre;
        property int precio;
        property List<Insumo^>^ receta;
    public:
        Bebida(int id, String^ nombre, int precio, List<Insumo^>^ receta); 
    };
}
#endif