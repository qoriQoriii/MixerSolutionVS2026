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
        static void Initialize();
        static void CreateMixer(int id, String^ ubi, String^ est, List<Bebida^>^ cat, List<Pedido^>^ ped, List<Tanque^>^ mat);
        static Mixer^ GetMixer(int id);
        static void UpdateStatus(int id, String^ status);
        static List<Mixer^>^ GetAllMixers();

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