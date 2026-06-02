#ifndef _MOTOR_H
#define _MOTOR_H
#include "Actuadores.h"

namespace ModelMixer {
    [Serializable]
    public ref class Motor : public Actuadores {
    public:
        property double torque;
    public:
        Motor(int id, String^ nombre, String^ estado, double torque);
  };
}
#endif