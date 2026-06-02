#ifndef _BEBIDA_H
#define _BEBIDA_H
#include "Insumo.h"
using namespace System;
using namespace System::Collections::Generic;

namespace ModelMixer {
    public ref class Bebida {
    private:
        int id;
        String^ nombre;
        int precio;
        LinkedList<Insumo^>^ receta;
    public:
        Bebida(int id, String^ nombre, int precio, LinkedList<Insumo^>^ receta);

        property int Id{ int get() { return id; } void set(int value) { id = value; } }
        property String^ Nombre{ String ^ get() { return nombre; } void set(String ^ value) { nombre = value; } }
        property int Precio{ int get() { return precio; } void set(int value) { precio = value; } }
        property LinkedList<Insumo^>^ Receta{ LinkedList<Insumo^> ^ get() { return receta; } void set(LinkedList<Insumo^> ^ value) { receta = value; } }
    };
}
#endif