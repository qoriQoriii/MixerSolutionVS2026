#include "pch.h"
#include "VentaController.h"


using namespace ModelMixer;
using namespace PersistenciaMixer;
// ============================================================
// VENTA CONTROLLER
// ============================================================
void ControllerMixer::VentaController::Initialize() {
    // Vacío por el momento
}

bool ControllerMixer::VentaController::CreateVenta(int id, String^ nombreBebida, int cantidad, double coste) {
    Venta^ v = gcnew Venta(id, nombreBebida, cantidad, coste);
    return PersistenciaManager::addVenta(v);
}

Venta^ ControllerMixer::VentaController::ReadVenta(int id) {
    return PersistenciaManager::getVentaById(id);
}

bool ControllerMixer::VentaController::UpdateVenta(int id, String^ nombreBebida, int cantidad, double coste) {
    Venta^ v = gcnew Venta(id, nombreBebida, cantidad, coste);
    return PersistenciaManager::updateVenta(v);
}

bool ControllerMixer::VentaController::DeleteVenta(int id) {
    return PersistenciaManager::deleteVentaById(id);
}

List<Venta^>^ ControllerMixer::VentaController::GetAllVentas() {
    listaVentas = PersistenciaManager::getAllVentas();
    return listaVentas;
}

