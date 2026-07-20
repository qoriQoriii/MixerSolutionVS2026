#ifndef _SENSOR_H
#define _SENSOR_H
#include "Componente.h"

namespace ModelMixer {
    [Serializable]
    public ref class Sensor {
    public:
        property double litrado;
    public:
        Sensor(int id, String^ nombre, String^ estado, double litrado);

 };
}
#endif