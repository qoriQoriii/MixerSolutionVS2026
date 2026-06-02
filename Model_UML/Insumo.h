#ifndef _INSUMO_H
#define _INSUMO_H
using namespace System;

namespace ModelMixer {
    public ref class Insumo {
    private:
        int id;
        String^ nombre;
        int stockActual;
        int stockMinimoAlerta;
    public:
        Insumo(int id, String^ nombre, int stockActual, int stockMinimo);

        property int Id{ int get() { return id; } void set(int value) { id = value; } }
        property String^ Nombre{ String ^ get() { return nombre; } void set(String ^ value) { nombre = value; } }
        property int StockActual{ int get() { return stockActual; } void set(int value) { stockActual = value; } }
        property int StockMinimoAlerta{ int get() { return stockMinimoAlerta; } void set(int value) { stockMinimoAlerta = value; } }
    };
}
#endif