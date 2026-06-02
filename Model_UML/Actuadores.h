#ifndef _ACTUADORES_H
#define _ACTUADORES_H
#include "Componente.h"

namespace ModelMixer {
    public ref class Actuadores : public Componente {
    public:
        Actuadores(int id, String^ nombre, String^ estado);
    };
}
#endif