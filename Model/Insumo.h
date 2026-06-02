#ifndef _INSUMO_H
#define _INSUMO_H

#include"InsumoBebida.h"
using namespace System;

namespace ModelMixer {
    [Serializable]
    public ref class Insumo : public InsumoBebida{
    public:
        property int stockActual;
        property int stockMinimoAlerta;
    public:
        Insumo(int id, String^ nombre, int stockActual, int stockMinimo);
 };
}
#endif