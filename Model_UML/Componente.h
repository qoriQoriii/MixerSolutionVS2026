#ifndef _COMPONENTE_H
#define _COMPONENTE_H
using namespace System;

namespace ModelMixer {
    public ref class Componente {
    private:
        int id;
        String^ nombre;
        String^ estado;
    public:
        Componente(int id, String^ nombre, String^ estado);

        property int Id{ int get() { return id; } void set(int value) { id = value; } }
        property String^ Nombre{ String ^ get() { return nombre; } void set(String ^ value) { nombre = value; } }
        property String^ Estado{ String ^ get() { return estado; } void set(String ^ value) { estado = value; } }
    };
}
#endif