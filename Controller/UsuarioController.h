#pragma once
#ifndef _USUARIOCONTROLLER_H
#define _USUARIOCONTROLLER_H



using namespace System;
using namespace System::Collections::Generic;
using namespace ModelMixer;
using namespace PersistenciaMixer;

namespace ControllerMixer {
    public ref class UsuarioController {
    private:
        static List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
    public:
        static void Initialize();
        // Create para Administrador
        static bool CreateUsuario(int id, String^ nom, String^ dni, String^ password, int edad, String^ tipo);
        static Usuario^ ReadUsuario(String^ dni);
        static bool UpdateUsuario(int id, String^ nom, String^ dni, String^ password, int edad, String^ tipo);
        static bool DeleteUsuario(String^ dni);
        static List<Usuario^>^ GetAllUsuarios();



        //persistencias
        static void Guardar() {
            PersistenciaMixer::PersistenciaManager::GuardarUsuarios(listaUsuarios);
        }
        static void Cargar() {
           listaUsuarios = PersistenciaMixer::PersistenciaManager::CargarUsuarios();
        }
    };
}
#endif
