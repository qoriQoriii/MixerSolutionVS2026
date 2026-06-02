#ifndef _CLIENTE_H
#define _CLIENTE_H
#include "Usuario.h"

namespace ModelMixer {
    [Serializable]
    public ref class Cliente : public Usuario {
    public:
        property int edadCliente;
    public:
        Cliente(int id, String^ nombre, int  dni, int edadCli);

  
    };
}
#endif