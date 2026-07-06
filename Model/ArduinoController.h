#pragma once

using namespace System;
using namespace System;
using namespace System::IO::Ports;

namespace ModelMixer {

    public ref class ArduinoController abstract sealed
    {
    private:
        static SerialPort^ _serialPort;

    public:
        // Evento estático: avisa cuando llega algo del Arduino
        static event Action<String^>^ OnDataReceived;

        static void Conectar(String^ puerto)
        {
            _serialPort = gcnew SerialPort(puerto, 9600);
            _serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(&ArduinoController::DataRecibida);
            _serialPort->Open();
        }

        static void EnviarComando(String^ comando)
        {
            if (_serialPort != nullptr && _serialPort->IsOpen)
                _serialPort->WriteLine(comando);
        }

        static void Desconectar()
        {
            if (_serialPort != nullptr && _serialPort->IsOpen)
                _serialPort->Close();
        }

    private:
        static void DataRecibida(Object^ sender, SerialDataReceivedEventArgs^ e)
        {
            String^ data = _serialPort->ReadLine()->Trim();
            OnDataReceived(data);
        }
    };
    
}