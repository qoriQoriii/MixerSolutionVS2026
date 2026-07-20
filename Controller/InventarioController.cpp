#include "pch.h"
#include "InventarioController.h"
/*

void ControllerMixer::InventarioController::Initialize() {
    // Inicializar insumos base como Agua, Café, etc.
}

void ControllerMixer::InventarioController::CreateInsumo(int id, String^ nom, int stockA, int stockM) {
    Insumo^ nuevo = gcnew Insumo(id, nom, stockA, stockM);
    listaInsumos->Add(nuevo);
}

Insumo^ ControllerMixer::InventarioController::ReadInsumo(int id) {
    for (int i = 0; i < listaInsumos->Count; i++) {
        if (listaInsumos[i]->id == id) return listaInsumos[i];
    }
    return nullptr;
}

List<Insumo^>^ ControllerMixer::InventarioController::GetAllInsumos()
{
    return listaInsumos;
}

void ControllerMixer::InventarioController::CreateBebida(int id, String^ nom, int precio, List<Insumo^>^ receta) {
    Bebida^ nueva = gcnew Bebida(id, nom, precio, receta);
    catalogo->Add(nueva);
}

Bebida^ ControllerMixer::InventarioController::ReadBebida(int id) {
    for (int i = 0; i < catalogo->Count; i++) {
        if (catalogo[i]->id == id) return catalogo[i];
    }
    return nullptr;
}

void ControllerMixer::InventarioController::DeleteBebida(int id) {
    for (int i = 0; i < catalogo->Count; i++) {
        if (catalogo[i]->id == id) {
            catalogo->RemoveAt(i);
            break;
        }
    }
}

List<Bebida^>^ ControllerMixer::InventarioController::GetAllBebidas()
{
    return catalogo;
}

List<String^>^ ControllerMixer::InventarioController::ObtenerNombresBebidas()
{
    return PersistenciaMixer::PersistenciaManager::ObtenerNombresBebidasSQL();
}

*/
void ControllerMixer::InventarioController::Initialize() {
    // Vacío por el momento
}

// ============================================================
//  BEBIDA CONTROLLER 
// ============================================================


bool ControllerMixer::InventarioController::CreateBebida(int id, String^ nombre, int precio, String^ estado, String^ proporcion) {
    Bebida^ b = gcnew Bebida(id, nombre, precio, estado, proporcion);
    return PersistenciaManager::addBebida(b);
}

Bebida^ ControllerMixer::InventarioController::ReadBebida(int id) {
    return PersistenciaManager::getBebidaById(id);
}

bool ControllerMixer::InventarioController::UpdateBebida(int id, String^ nombre, int precio, String^ estado, String^ proporcion) {
    Bebida^ b = gcnew Bebida(id, nombre, precio, estado, proporcion);
    return PersistenciaManager::updateBebida(b);
}

bool ControllerMixer::InventarioController::DeleteBebida(int id) {
    return PersistenciaManager::deleteBebidaById(id);
}

List<Bebida^>^ ControllerMixer::InventarioController::GetAllBebidas() {
    listaBebidas = PersistenciaManager::getAllBebidas();
    return listaBebidas;
}

// ============================================================
// INSUMO CONTROLLER
// ============================================================


bool ControllerMixer::InventarioController::CreateInsumo(int id, String^ nombre, int stockActual, int stockMinimoAlerta) {
    Insumo^ i = gcnew Insumo(id, nombre, stockActual, stockMinimoAlerta);
    return PersistenciaManager::addInsumo(i);
}

Insumo^ ControllerMixer::InventarioController::ReadInsumo(int id) {
    return PersistenciaManager::getInsumoById(id);
}

bool ControllerMixer::InventarioController::UpdateInsumo(int id, String^ nombre, int stockActual, int stockMinimoAlerta) {
    Insumo^ i = gcnew Insumo(id, nombre, stockActual, stockMinimoAlerta);
    return PersistenciaManager::updateInsumo(i);
}

bool ControllerMixer::InventarioController::DeleteInsumo(int id) {
    return PersistenciaManager::deleteInsumoById(id);
}

List<Insumo^>^ ControllerMixer::InventarioController::GetAllInsumos() {
    listaInsumos = PersistenciaManager::getAllInsumos();
    return listaInsumos;
}