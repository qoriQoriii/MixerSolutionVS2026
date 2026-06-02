/**
 * Project Untitled
 */


#ifndef _INSUMOBEBIDA_H
#define _INSUMOBEBIDA_H

using namespace System;

namespace ModelMixer {
    [Serializable]
    public ref class InsumoBebida {
    public:
        property int id;
        property String^ nombre;

        InsumoBebida(int id, String^ nombre);
    };
}
#endif //_INSUMOBEBIDA_H