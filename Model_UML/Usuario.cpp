#include "pch.h"
#include "Usuario.h"
ModelMixer::Usuario::Usuario(int id, String^ nombre, int edad, String^ dni, String^ nombreYApellido) {
    this->idUsuario = id;
    this->nombre = nombre;
    this->edad = edad;
    this->dni = dni;
    this->nombreYApellido = nombreYApellido;
}