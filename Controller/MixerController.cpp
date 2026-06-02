#include "pch.h"
#include "MixerController.h"

void ControllerMixer::MixerController::Initialize() {
    // Configuración inicial del Mixer principal
}

void ControllerMixer::MixerController::CreateMixer(int id, String^ ubi, String^ est, List<Bebida^>^ cat, List<Pedido^>^ ped, List<Tanque^>^ mat) {
    listaMixers->Add(gcnew Mixer(id, ubi, est, cat, ped, mat));
}

Mixer^ ControllerMixer::MixerController::GetMixer(int id) {
    for (int i = 0; i < listaMixers->Count; i++) {
        if (listaMixers[i]->id == id) return listaMixers[i];
    }
    return nullptr;
}

void ControllerMixer::MixerController::UpdateStatus(int id, String^ status) {
    Mixer^ m = GetMixer(id);
    if (m != nullptr) m->estado = status;
}

List<Mixer^>^ ControllerMixer::MixerController::GetAllMixers()
{
    return listaMixers;
}
