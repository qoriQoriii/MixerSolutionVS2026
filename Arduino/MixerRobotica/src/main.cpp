#include <Arduino.h>
#include "Recetas.h"
#include "Config.h"
void setup() {
    Serial.begin(9600);
    inicializarTodoElHardware();
    Serial.println("SISTEMA_LISTO"); 
}


void loop() {
    if (Serial.available() > 0) {
        String comando = Serial.readStringUntil('\n');
        comando.trim();

        if (comando.startsWith("PEDIDO:")) {
            // Quitamos el prefijo "PEDIDO:" para quedarnos solo con "0,1,1,0"
            String datos = comando.substring(7); 

            // Arreglo temporal para guardar los 4 valores
            int recetaRecibida[numeroIngredientes] = {0, 0, 0, 0};
            int indiceValores = 0;

            // Procesar el string separado por comas (Parsing masivo)
            while (datos.length() > 0 && indiceValores < numeroIngredientes) {
                int posComa = datos.indexOf(',');
                
                if (posComa == -1) {
                    // Ya no hay más comas, es el último número
                    recetaRecibida[indiceValores] = datos.toInt();
                    datos = ""; // Termina el bucle
                } else {
                    // Extrae el número antes de la coma
                    recetaRecibida[indiceValores] = datos.substring(0, posComa).toInt();
                    // Recorta el string para procesar lo que queda
                    datos = datos.substring(posComa + 1);
                }
                indiceValores++;
            }

            // Enviamos el arreglo extraído a procesar
            bool exito = procesarPedidoBebida(recetaRecibida);

            if (exito) {
                Serial.println("BEBIDA_LISTA");
            } else {
                Serial.println("PROCESO_FALLIDO");
            }
        }
    }
}