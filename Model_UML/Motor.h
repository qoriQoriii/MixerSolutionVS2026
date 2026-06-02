#ifndef _MOTOR_H
#define _MOTOR_H
#include "Actuadores.h"

namespace ModelMixer {
    public ref class Motor : public Actuadores {
    private:
        double torque;
    public:
        Motor(int id, String^ nombre, String^ estado, double torque);

        property double Torque{ double get() { return torque; } void set(double value) { torque = value; } }
    };
}
#endif