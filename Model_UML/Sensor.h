#ifndef _SENSOR_H
#define _SENSOR_H
#include "Componente.h"

namespace ModelMixer {
    public ref class Sensor : public Componente {
    private:
        double litrado;
    public:
        Sensor(int id, String^ nombre, String^ estado, double litrado);

        property double Litrado{ double get() { return litrado; } void set(double value) { litrado = value; } }
    };
}
#endif