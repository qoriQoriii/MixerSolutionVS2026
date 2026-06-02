#ifndef _USUARIO_H
#define _USUARIO_H
using namespace System;

namespace ModelMixer {
    public ref class Usuario {
    private:
        int idUsuario;
        String^ nombre;
        int edad;
        String^ dni;
        String^ nombreYApellido;
    public:
        Usuario(int id, String^ nombre, int edad, String^ dni, String^ nombreYApellido);

        property int IdUsuario{ int get() { return idUsuario; } void set(int value) { idUsuario = value; } }
        property String^ Nombre{ String ^ get() { return nombre; } void set(String ^ value) { nombre = value; } }
        property int Edad{ int get() { return edad; } void set(int value) { edad = value; } }
        property String^ Dni{ String ^ get() { return dni; } void set(String ^ value) { dni = value; } }
        property String^ NombreYApellido{ String ^ get() { return nombreYApellido; } void set(String ^ value) { nombreYApellido = value; } }
    };
}
#endif