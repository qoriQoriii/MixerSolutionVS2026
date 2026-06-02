#ifndef _TANQUE_H
#define _TANQUE_H
#include "Componente.h"
#include "Insumo.h"

namespace ModelMixer {
    public ref class Tanque : public Componente {
    private:
        Insumo^ insumo;
        double nivelAgua;
    public:
        Tanque(int id, String^ nombre, String^ estado, Insumo^ insumo, double nivel);

        property Insumo^ Contenido{ Insumo ^ get() { return insumo; } void set(Insumo ^ value) { insumo = value; } }
        property double NivelAgua{ double get() { return nivelAgua; } void set(double value) { nivelAgua = value; } }
    };
}
#endif