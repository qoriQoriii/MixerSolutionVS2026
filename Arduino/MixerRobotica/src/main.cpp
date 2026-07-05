#include <Arduino.h>
#include "Recetas.h"
#include "Config.h"
#include "Sensores.h"


void setup() {
    Serial.begin(9600);
    inicializarTodoElHardware();
    Serial.println("SISTEMA_LISTO"); 
}

void loop() {

    //Leemos constantemente es espera de un comando dede la pc
    if (Serial.available() > 0) {

        String comando = Serial.readStringUntil('\n');
        comando.trim();
        String mensaje = "";

        switch (parsearComando(comando)) {
            
            //La pc envio "PEDIDO:1,0,1,0" POR EJEMPLO  
            case CMD_PEDIDO: {
                String datos = comando.substring(7);

                int recetaRecibida[numeroTanques] = {};
                int indiceValores = 0;

                while (datos.length() > 0 && indiceValores < numeroTanques) {
                    int posComa = datos.indexOf(',');

                    if (posComa == -1) {
                        recetaRecibida[indiceValores] = datos.toInt();
                        datos = "";
                    } else {
                        recetaRecibida[indiceValores] = datos.substring(0, posComa).toInt();
                        datos = datos.substring(posComa + 1);
                    }
                    indiceValores++;
                }

                bool exito = procesarPedidoBebida(recetaRecibida);

                //Enviamos un comando hacia la pc para confirmar si el pedido fue procesado adecuadamente
                mensaje = exito ? "BEBIDA_LISTA" : "PROCESO_FALLIDO";
                break;
            }

            case CMD_REPORTE_TANQUE:
            
                GenerarReporteTanques();

                for(int i = 0;  i < numeroTanques; i++){
                    mensaje += reporteTanque[i] + "|";
                }

                break;

            case CMD_DESCONOCIDO:
                mensaje = "COMANDO DESCONOCIDO";
            default:
                mensaje = "ERROR_COMANDO";
                break;

        }
        Serial.println(mensaje);
    }
}