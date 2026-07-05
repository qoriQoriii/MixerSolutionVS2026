#include <Arduino.h>
#include "Servos.h"
#include "Sensores.h"
#include "Motor.h"
#include "Recetas.h"
#include "Config.h"
#include "BombaAgua.h"

void inicializarTodoElHardware() {
    //inicializarServos();
    inicializarSensores();
    inicializarMotor();
    inicializarBombas();
}
     
#include <Arduino.h>
#include "Servos.h"
#include "Sensores.h"
#include "Motor.h"
#include "Recetas.h"
#include "Config.h"

bool procesarPedidoBebida(int ingredientes[numeroTanques]) {
    
    // ============================================================
    // FASE 1: VALIDACIÓN DE TANQUES (Solo los necesarios)
    // ============================================================
    bool tanquesListos = true;
    String reporteFaltantes = "ERROR_FALTA:"; // Prefijo para enviar a Visual Studio 2026

    for (int i = 0; i < numeroTanques; i++) {
        // Solo validamos el tanque si la receta pide ese ingrediente (ingredientes[i] == 1)
        if (ingredientes[i] == 1) {
            int lecturaActual = leerDistancia(i + 1); // Sensor i corresponde a Servo i

            // Validación del tope (lectura debe ser mayor a ReservaMinimaTanque)
            // También protegemos el sistema si el sensor falla y devuelve -1
            if (lecturaActual <= LecturaMinimaTanqueDistancia || lecturaActual == -1) {
                tanquesListos = false;
                
                // Concatenamos el número del ingrediente faltante (1, 2, 3 o 4)
                reporteFaltantes += String(i + 1) + " "; 
            }
        }
    }

    // Si al menos un tanque requerido no pasó la validación, cancelamos todo
    if (!tanquesListos) {
        reporteFaltantes.trim(); // Limpia espacios sobrantes
        Serial.println(reporteFaltantes); // Envía ej: "ERROR_FALTA:1 3" a la PC
        return false; 
    }

    // ============================================================
    // FASE 2: EJECUCIÓN DE LA RECETA (Servido simultáneo)
    // ============================================================
    // Activamos las bombas:

    encenderApagarBombas(ingredientes[0], ingredientes[1], ingredientes[2], ingredientes[3]);



    /* Lógica con servos en lugar de bombas, si decides usar servos para abrir válvulas:
    for (int i = 0; i < numeroTanques; i++) {
        if (ingredientes[i] == 1) {


            
            moverServo(i + 1, 180); // Abre válvula
        } else {
            moverServo(i + 1, 90);  // Mantiene cerrado
        }
    }
    
    */


    // Esperamos el tiempo de servido con los servos en su posición
    delay(delayServido);

    //Apagamos las bombas después del tiempo de servido
    apagarAllBombas();  


    /* Lógica con servos en lugar de bombas, si decides usar servos para abrir válvulas:
        // Al terminar el tiempo, cerramos ABSOLUTAMENTE TODOS los servos a 90°
    for (int i = 0; i < numeroTanques; i++) {
        moverServo(i + 1, 90);
    }
    */

    
    // Pequeña pausa de seguridad antes de activar el mezclador
    delay(500); 

    return true; // Todo el proceso fue exitoso
}

