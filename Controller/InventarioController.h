#pragma once
#ifndef _INVENTARIOCONTROLLER_H
#define _INVENTARIOCONTROLLER_H



using namespace ModelMixer;
using namespace PersistenciaMixer;
using namespace System;
using namespace System::Collections::Generic;

namespace ControllerMixer {
    public ref class InventarioController {
    private:
        static List<Insumo^>^ listaInsumos = gcnew List<Insumo^>();
        static List<Bebida^>^ catalogo = gcnew List<Bebida^>();
    public:
        static void Initialize();

        // CRUD Insumos
        static void CreateInsumo(int id, String^ nom, int stockA, int stockM);
        static Insumo^ ReadInsumo(int id);
        static  List<Insumo^>^ GetAllInsumos();

        // CRUD Bebidas
        static void CreateBebida(int id, String^ nom, int precio, List<Insumo^>^ receta);
        static Bebida^ ReadBebida(int id);
        static void DeleteBebida(int id);
        static  List<Bebida^>^ GetAllBebidas();
        static List<String^>^ ObtenerNombresBebidas()


        //persistencias xd

        static void Guardar() {
            PersistenciaMixer::PersistenciaManager::GuardarInsumos(listaInsumos);
            PersistenciaMixer::PersistenciaManager::GuardarBebidas(catalogo);
        }
        static void Cargar() {
           
                listaInsumos = PersistenciaMixer::PersistenciaManager::CargarInsumos();
        }
    };
}
#endif


