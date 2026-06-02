#include "pch.h"
#include "PedidoController.h"

void ControllerMixer::PedidoController::Create(String^ datos, double precio) {
    listaPedidos->Add(gcnew Pedido(datos, precio));
}

List<Pedido^>^ ControllerMixer::PedidoController::GetAllPedidos() {
    return listaPedidos;
}

void ControllerMixer::PedidoController::ClearHistory() {
    listaPedidos->Clear();
}