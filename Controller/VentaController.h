#pragma once
#ifndef _VENTACONTROLLER_H
#define _VENTACONTROLLER_H

using namespace System;
using namespace System::Collections::Generic;

namespace ModelMixer { ref class Venta; }

namespace ControllerMixer {
    public ref class VentaController {
    private:
        static List<ModelMixer::Venta^>^ listaVentas = gcnew List<ModelMixer::Venta^>();
    public:
        static void Initialize();
        static void RegistrarNuevaVenta(String^ nombreBebida, int cantidad, double coste);
        static List<ModelMixer::Venta^>^ GetAllVentas();

        static void Guardar();
        static void Cargar();
    };
}
#endif