#ifndef _MIXER_H
#define _MIXER_H
#include "Bebida.h"
#include "Pedido.h"
#include "Tanque.h"
using namespace System;
using namespace System::Collections::Generic;

namespace ModelMixer {
    [Serializable]
    public ref class Mixer {
    public:
        property int id;
        property String^ ubicacion;
        property String^ estado;

    public:
        Mixer(int id, String^ ubicacion, String^ estado) {
            this->id = id;
            this->ubicacion = ubicacion;
            this->estado = estado;
        };

        Mixer( String^ ubicacion, String^ estado) {
            this->id = id;
            this->ubicacion = ubicacion;
            this->estado = estado;
        };


    };
}
#endif