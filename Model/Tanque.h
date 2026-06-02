#ifndef _TANQUE_H
#define _TANQUE_H
#include "Componente.h"
#include "Insumo.h"

namespace ModelMixer {
    [Serializable]
    public ref class Tanque : public Componente {
    public:
        property Insumo^ insumo;
        property double nivelAgua;
    public:
        Tanque(int id, String^ nombre, String^ estado, Insumo^ insumo, double nivel);

   };
}
#endif