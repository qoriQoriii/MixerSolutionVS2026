#include "pch.h"
#include "HadwareController.h"


using namespace System;
using namespace ModelMixer;

void ControllerMixer::HardwareController::Initialize() {
    // Aquí se instanciarían los motores, válvulas y sensores físicos de la máquina
}

void ControllerMixer::HardwareController::AddMotor(int id, String^ nom, String^ est, double torque) {
    listaDispositivos->Add(gcnew Motor(id, nom, est, torque));
}

void ControllerMixer::HardwareController::AddValvula(int id, String^ nom, String^ est, double flujo, double tiempo) {
    listaDispositivos->Add(gcnew Valvula(id, nom, est, flujo, tiempo));
}

void ControllerMixer::HardwareController::AddSensor(int id, String^ nom, String^ est, double litrado) {
    listaDispositivos->Add(gcnew Sensor(id, nom, est, litrado));
}

void ControllerMixer::HardwareController::AddTanque(int id, String^ nom, String^ est, Insumo^ ins, double nivel) {
    listaDispositivos->Add(gcnew Tanque(id, nom, est, ins, nivel));
}

Componente^ ControllerMixer::HardwareController::GetById(int id) {
    for (int i = 0; i < listaDispositivos->Count; i++) {
        if (listaDispositivos[i]->id == id) return listaDispositivos[i];
    }
    return nullptr;
}

void ControllerMixer::HardwareController::UpdateEstado(int id, String^ nuevoEstado) {
    Componente^ comp = GetById(id);
    if (comp != nullptr) comp->estado = nuevoEstado;
}

List<Componente^>^ ControllerMixer::HardwareController::GetAllDispositivos()
{
    return listaDispositivos;
}
