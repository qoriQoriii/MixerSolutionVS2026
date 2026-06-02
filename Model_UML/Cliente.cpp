#include "pch.h"
#include "Cliente.h"
ModelMixer::Cliente::Cliente(int id, String^ nombre, int edadUsuario, String^ dni, String^ nombreYApellido, int edadCli)
    : Usuario(id, nombre, edadUsuario, dni, nombreYApellido) {
    this->edadCliente = edadCli;
}