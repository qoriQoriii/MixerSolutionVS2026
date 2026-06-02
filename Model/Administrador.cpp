#include "pch.h"


#include "Administrador.h"
ModelMixer::Administrador::Administrador(int id, String^ nombre,int dni, String^ contrasena)
    : Usuario(id, nombre, dni) {
    this->contrasena = contrasena;
}
