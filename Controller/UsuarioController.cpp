#include "pch.h"
#include "UsuarioController.h"

void ControllerMixer::UsuarioController::Initialize() {
    //Vacio por el momento
}




bool ControllerMixer::UsuarioController::CreateUsuario(int id, String^ nom, String^ dni, String^ password, int edad, String^ tipo) {
    Usuario^ u =gcnew  Usuario(id, nom, dni, password, edad, tipo);
    return PersistenciaManager::addUsuario(u);

}


Usuario^ ControllerMixer::UsuarioController::ReadUsuario(String^ dni) {
    return PersistenciaManager::getUsuarioByDNI(dni);
}

bool ControllerMixer::UsuarioController::UpdateUsuario(int id, String^ nom, String^ dni, String^ password, int edad, String^ tipo)
{
    Usuario^ u = gcnew  Usuario(id, nom, dni, password, edad, tipo);
    return PersistenciaManager::updateUsuario(u);
}


bool ControllerMixer::UsuarioController::DeleteUsuario(String^ dni) {
    return PersistenciaManager::deleteUsuarioByDNI(dni);
}

List<Usuario^>^ ControllerMixer::UsuarioController::GetAllUsuarios()
{
    listaUsuarios = PersistenciaManager::getAllUsuarios();

    return listaUsuarios;
}