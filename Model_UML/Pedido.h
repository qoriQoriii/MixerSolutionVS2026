#ifndef _PEDIDO_H
#define _PEDIDO_H
using namespace System;

namespace ModelMixer {
    public ref class Pedido {
    private:
        String^ datosDelCliente;
        double precio;
    public:
        Pedido(String^ datos, double precio);

        property String^ DatosDelCliente{ String ^ get() { return datosDelCliente; } void set(String ^ value) { datosDelCliente = value; } }
        property double Precio{ double get() { return precio; } void set(double value) { precio = value; } }
    };
}
#endif