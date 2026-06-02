#ifndef _COMPONENTE_H
#define _COMPONENTE_H
using namespace System;

namespace ModelMixer {
    [Serializable]
    public ref class Componente {
    public:
        property int id;
        property String^ nombre;
        property String^ estado;
    public:
        Componente(int id, String^ nombre, String^ estado);
    };
}
#endif