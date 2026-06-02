#ifndef _CLIENTE_H
#define _CLIENTE_H
#include "Usuario.h"

namespace ModelMixer {
    public ref class Cliente : public Usuario {
    private:
        int edadCliente;
    public:
        Cliente(int id, String^ nombre, int edadUsuario, String^ dni, String^ nombreYApellido, int edadCli);

        property int EdadCliente{ int get() { return edadCliente; } void set(int value) { edadCliente = value; } }
    };
}
#endif