#ifndef _VALVULA_H
#define _VALVULA_H
#include "Actuadores.h"

namespace ModelMixer {
    [Serializable]
    public ref class Valvula : public Actuadores {
    public:
        property double flujo;
        property double tiempoApertura;
    public:
        Valvula(int id, String^ nombre, String^ estado, double flujo, double tiempo);
  };
}
#endif