#ifndef _ADMINISTRADOR_H
#define _ADMINISTRADOR_H
#include "Usuario.h"

namespace ModelMixer {
    public ref class Administrador : public Usuario {
    private:
        String^ contrasena;
    public:
        Administrador(int id, String^ nombre, int edad, String^ dni, String^ nombreYApellido, String^ contrasena);

        property String^ Contrasena{ String ^ get() { return contrasena; } void set(String ^ value) { contrasena = value; } }
    };
}
#endif