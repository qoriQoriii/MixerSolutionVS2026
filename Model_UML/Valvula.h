#ifndef _VALVULA_H
#define _VALVULA_H
#include "Actuadores.h"

namespace ModelMixer {
    public ref class Valvula : public Actuadores {
    private:
        double flujo;
        double tiempoApertura;
    public:
        Valvula(int id, String^ nombre, String^ estado, double flujo, double tiempo);

        property double Flujo{ double get() { return flujo; } void set(double value) { flujo = value; } }
        property double TiempoApertura{ double get() { return tiempoApertura; } void set(double value) { tiempoApertura = value; } }
    };
}
#endif