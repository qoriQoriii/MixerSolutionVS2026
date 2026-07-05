#include "pch.h"
#include "VentaController.h"


using namespace ModelMixer;
using namespace PersistenciaMixer;

void ControllerMixer::VentaController::Initialize() {
    Cargar();
}

void ControllerMixer::VentaController::RegistrarNuevaVenta(String^ nombreBebida, int cantidad, double coste) {
    Cargar();

    int nuevoId = listaVentas->Count + 1;
    String^ fechaActual = System::DateTime::Now.ToString(L"dd/MM/yyyy HH:mm");

    // Instanciación exacta usando tu constructor heredado de Componente
    Venta^ nuevaVenta = gcnew Venta(nuevoId, nombreBebida, cantidad, coste, fechaActual);
    listaVentas->Add(nuevaVenta);

    Guardar();
}

List<ModelMixer::Venta^>^ ControllerMixer::VentaController::GetAllVentas() {
    return listaVentas;
}

void ControllerMixer::VentaController::Guardar() {
    // Llamada directa sin bucles de inclusión
    PersistenciaManager::GuardarVentas(listaVentas);
}

void ControllerMixer::VentaController::Cargar() {
    // Llamada directa sin bucles de inclusión
    listaVentas = PersistenciaManager::CargarVentas();
}