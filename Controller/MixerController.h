
#pragma once
#ifndef _MIXERCONTROLLER_H
#define _MIXERCONTROLLER_H



using namespace ModelMixer;
using namespace PersistenciaMixer;
using namespace System;
using namespace System::Collections::Generic;

namespace ControllerMixer {
    public ref class MixerController {
    private:
        static List<Mixer^>^ listaMixers = gcnew List<Mixer^>();
    public:

        //CRUD Mixers
        static bool CreateMixer(int id, String^ ubicacion, String^ estado);
        static List<Mixer^>^ GetAllMixers();
        static Mixer^ ReadMixer(int id);
        static bool UpdateMixer(int id, String^ ubicacion, String^ estado);
        static bool DeleteMixer(int id);

        ///persistencia

        static void Guardar() {
            PersistenciaMixer::PersistenciaManager::GuardarMixers(listaMixers);
        }
        static void Cargar() {
            listaMixers = PersistenciaMixer::PersistenciaManager::CargarMixers();
        }

    };
}
#endif