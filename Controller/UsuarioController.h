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
        static void CreateAdmin(int id, String^ nom, int dni, String^ password);
        // Create para Cliente
        static void CreateCliente(int id, String^ nom, int dni, int edadC);

        static Usuario^ Read(int dni);
        static void Update(int dni, String^ nuevoNombre);
        static void Delete(int dni);

        static List<Usuario^>^ GetAllUsers();



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
