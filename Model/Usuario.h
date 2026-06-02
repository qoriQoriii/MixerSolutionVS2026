#ifndef _USUARIO_H
#define _USUARIO_H
using namespace System;

namespace ModelMixer {
    [Serializable]
    public ref class Usuario {
    public:
        property int idUsuario;
        property String^ nombre;
        property int dni;

    public:
        Usuario(int id, String^ nombre, int dni);
  };
}
#endif