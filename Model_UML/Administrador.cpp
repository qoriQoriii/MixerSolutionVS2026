#include "pch.h"


#include "Administrador.h"
ModelMixer::Administrador::Administrador(int id, String^ nombre, int edad, String^ dni, String^ nombreYApellido, String^ contrasena)
    : Usuario(id, nombre, edad, dni, nombreYApellido) {
    this->contrasena = contrasena;
}
