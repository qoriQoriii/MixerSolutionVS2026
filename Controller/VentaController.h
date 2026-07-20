#pragma once
#ifndef _VENTACONTROLLER_H
#define _VENTACONTROLLER_H

using namespace System;
using namespace System::Collections::Generic;

using namespace ModelMixer;

namespace ControllerMixer {
    public ref class VentaController {
    private:
        static List<Venta^>^ listaVentas = gcnew List<Venta^>();
    public:

        // ============================================================
        // 3. VENTA CONTROLLER
        // ============================================================
        static void Initialize();
        static bool CreateVenta(int id, String^ nombreBebida, int cantidad, double coste);
        static Venta^ ReadVenta(int id);
        static bool UpdateVenta(int id, String^ nombreBebida, int cantidad, double coste);
        static bool DeleteVenta(int id);
        static List<Venta^>^ GetAllVentas();

        static void Guardar() {};
        static void Cargar() {};
    };
}
#endif