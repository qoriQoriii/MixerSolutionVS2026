#ifndef _MIXER_H
#define _MIXER_H
#include "Bebida.h"
#include "Pedido.h"
#include "Tanque.h"
using namespace System;
using namespace System::Collections::Generic;

namespace ModelMixer {
    public ref class Mixer {
    private:
        int id;
        String^ ubicacion;
        String^ estado;
        LinkedList<Bebida^>^ catalogo;
        LinkedList<Pedido^>^ pedidos;
        LinkedList<Tanque^>^ materiaPrima;
    public:
        Mixer(int id, String^ ubi, String^ est, LinkedList<Bebida^>^ cat, LinkedList<Pedido^>^ ped, LinkedList<Tanque^>^ mat);

        property int Id{ int get() { return id; } void set(int value) { id = value; } }
        property String^ Ubicacion{ String ^ get() { return ubicacion; } void set(String ^ value) { ubicacion = value; } }
        property String^ Estado{ String ^ get() { return estado; } void set(String ^ value) { estado = value; } }
        property LinkedList<Bebida^>^ Catalogo{ LinkedList<Bebida^> ^ get() { return catalogo; } void set(LinkedList<Bebida^> ^ value) { catalogo = value; } }
        property LinkedList<Pedido^>^ ListaPedidos{ LinkedList<Pedido^> ^ get() { return pedidos; } void set(LinkedList<Pedido^> ^ value) { pedidos = value; } }
        property LinkedList<Tanque^>^ MateriaPrima{ LinkedList<Tanque^> ^ get() { return materiaPrima; } void set(LinkedList<Tanque^> ^ value) { materiaPrima = value; } }
    };
}
#endif