#include "pch.h"
#include "UsuarioController.h"

void ControllerMixer::UsuarioController::Initialize() {
    // Ejemplo de inicialización de un administrador
    CreateAdmin(1, "admin", 87654321, "1234");
}



void ControllerMixer::UsuarioController::CreateAdmin(int id, String^ nom, int dni, String^ password) {
    Administrador^ nuevo = gcnew Administrador(id, nom, dni,password);
    listaUsuarios->Add(nuevo);
}

void ControllerMixer::UsuarioController::CreateCliente(int id, String^ nom, int dni,int edadC)
{
    Cliente^ nuevo = gcnew Cliente(id, nom, dni, edadC);
    listaUsuarios->Add(nuevo);
}



Usuario^ ControllerMixer::UsuarioController::Read(int dni) {
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->dni == dni) {
            return listaUsuarios[i];
        }
    }
    return nullptr;
}

void ControllerMixer::UsuarioController::Update(int dni, String^ nuevoNombre)
{
    Usuario^ u = Read(dni);
    if (u != nullptr) {
        u->nombre = nuevoNombre;
    }
}


void ControllerMixer::UsuarioController::Delete(int dni) {
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->dni == dni) {
            listaUsuarios->RemoveAt(i);
            break;
        }
    }
}

List<Usuario^>^ ControllerMixer::UsuarioController::GetAllUsers()
{
    return listaUsuarios;
}
