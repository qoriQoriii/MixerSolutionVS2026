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
        property List<Bebida^>^ catalogo;
        property List<Pedido^>^ pedidos;
        property List<Tanque^>^ materiaPrima;
    public:
        Mixer(int id, String^ ubi, String^ est, List<Bebida^>^ cat, List<Pedido^>^ ped, List<Tanque^>^ mat);

    };
}
#endif