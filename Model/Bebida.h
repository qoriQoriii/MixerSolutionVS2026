#ifndef _BEBIDA_H
#define _BEBIDA_H

using namespace System;

namespace ModelMixer {
    [Serializable]
    public ref class Bebida {
    public:
        property int id;
        property String^ nombre;
        property int precio;
        property String^ estado;
        property String^ proporcion;

    public:
        Bebida(int id, String^ nombre, int precio, String^ estado, String^ proporcion) {
            this->id = id;
            this->nombre = nombre;
            this->precio = precio;
            this->estado = estado;
            this->proporcion = proporcion;
        };
    };
}

#endif