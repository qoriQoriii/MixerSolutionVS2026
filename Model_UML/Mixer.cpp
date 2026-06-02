#include "pch.h"
#include "Mixer.h"
ModelMixer::Mixer::Mixer(int id, String^ ubi, String^ est, LinkedList<Bebida^>^ cat, LinkedList<Pedido^>^ ped, LinkedList<Tanque^>^ mat) {
    this->id = id;
    this->ubicacion = ubi;
    this->estado = est;
    this->catalogo = cat;
    this->pedidos = ped;
    this->materiaPrima = mat;
}