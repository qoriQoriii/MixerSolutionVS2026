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
        static List<Bebida^>^ listaBebidas = gcnew List<Bebida^>();
    public:
        static void Initialize();

        // CRUD Insumos
   
        static bool CreateInsumo(int id, String^ nombre, int stockActual, int stockMinimoAlerta);
        static Insumo^ ReadInsumo(int id);
        static bool UpdateInsumo(int id, String^ nombre, int stockActual, int stockMinimoAlerta);
        static bool DeleteInsumo(int id);
        static List<Insumo^>^ GetAllInsumos();

        // CRUD Bebidas
        static bool CreateBebida(int id, String^ nombre, int precio, String^ estado, String^ proporcion);
        static Bebida^ ReadBebida(int id);
        static bool UpdateBebida(int id, String^ nombre, int precio, String^ estado, String^ proporcion);
        static bool DeleteBebida(int id);
        static List<Bebida^>^ GetAllBebidas();


        //Funciones de manejo

        static String^ GenerarStringPedido(String^ bebidaNombre, String^ hielo) {
            String^ proporcionFormateada = "0,0,0,0"; // Valor por defecto si no se encuentra

            // 1. Buscar la bebida en la lista por nombre
            List<Bebida^>^ listaBebidas = GetAllBebidas();

            for each (Bebida ^ b in listaBebidas) {
                if (String::Equals(b->nombre, bebidaNombre, StringComparison::OrdinalIgnoreCase)) {

                    // Si la proporción es tipo "0001", la formateamos a "0,0,0,1"
                    if (!String::IsNullOrEmpty(b->proporcion)) {
                        if (b->proporcion->Contains(",")) {
                            proporcionFormateada = b->proporcion;
                        }
                        else {
                            // Separa cada caracter con comas (Ej: "0001" -> "0,0,0,1")
                            List<String^>^ digitos = gcnew List<String^>();
                            for (int i = 0; i < b->proporcion->Length; i++) {
                                digitos->Add(b->proporcion[i].ToString());
                            }
                            proporcionFormateada = String::Join(",", digitos);
                        }
                    }
                    break;
                }
            }

            // 2. Determinar el valor del hielo (1 si es "si" / "sí", 0 si es "no")
            int valHielo = 0;
            if (!String::IsNullOrEmpty(hielo) &&
                (String::Equals(hielo->Trim(), "si", StringComparison::OrdinalIgnoreCase) ||
                    String::Equals(hielo->Trim(), "sí", StringComparison::OrdinalIgnoreCase))) {
                valHielo = 1;
            }

            // 3. Retornar el string final formateado
            return String::Format("PEDIDO:{0},{1}", proporcionFormateada, valHielo);
        }

        //persistencias xd

        static void Guardar() {
            PersistenciaMixer::PersistenciaManager::GuardarInsumos(listaInsumos);
            PersistenciaMixer::PersistenciaManager::GuardarBebidas(listaBebidas);
        }
        static void Cargar() {
           
                listaInsumos = PersistenciaMixer::PersistenciaManager::CargarInsumos();
        }
    };
}
#endif


