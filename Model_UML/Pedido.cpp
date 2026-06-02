#include "pch.h"
#include "Pedido.h"
ModelMixer::Pedido::Pedido(String^ datos, double precio) {
    this->datosDelCliente = datos;
    this->precio = precio;
}