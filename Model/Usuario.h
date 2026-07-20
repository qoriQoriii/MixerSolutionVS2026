#ifndef _USUARIO_H
#define _USUARIO_H
using namespace System;

namespace ModelMixer {
    [Serializable]
    public ref class Usuario {
    public:
        property int idUsuario;
        property String^ Nombre;
        property String^ DNI;
        property String^ Contrasena;
        property int EdadCliente;
        property String^ TipoUsuario;

    public:
        Usuario(int idUsuario, String^ nombre, String^ dni, String^ contrasena, int EdadCliente, String^ TipoUsuario) {

            this->idUsuario = idUsuario;
            this->Nombre = nombre;
            this->DNI = dni;
            this->Contrasena = contrasena;
            this->EdadCliente = EdadCliente;
            this->TipoUsuario = TipoUsuario;


        };
        Usuario(int idUsuario, String^ nombre, String^ dni, String^ contrasena, String^ TipoUsuario) {

            this->idUsuario = idUsuario;
            this->Nombre = nombre;
            this->DNI = dni;
            this->Contrasena = contrasena;
            this->TipoUsuario = TipoUsuario;


        };
  };
}
#endif