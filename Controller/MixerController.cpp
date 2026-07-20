#include "pch.h"
#include "MixerController.h"

namespace ControllerMixer {



    bool MixerController::CreateMixer(int id, String^ ubicacion, String^ estado) {
        Mixer^ m = gcnew Mixer(id, ubicacion, estado);
        return PersistenciaManager::AddMixer(m);
    }

    List<Mixer^>^ MixerController::GetAllMixers() {
        return PersistenciaManager::GetAllMixers();
    }

    Mixer^ MixerController::ReadMixer(int id) {
        return PersistenciaManager::ReadMixer(id);
    }

    bool MixerController::UpdateMixer(int id, String^ ubicacion, String^ estado) {
        Mixer^ m = gcnew Mixer(id, ubicacion, estado);
        return PersistenciaManager::UpdateMixer(m);
    }

    bool MixerController::DeleteMixer(int id) {
        return PersistenciaManager::DeleteMixer(id);
    }

}