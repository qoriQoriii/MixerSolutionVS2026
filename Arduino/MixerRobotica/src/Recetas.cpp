#include <Arduino.h>
#include "Servos.h"
#include "Sensores.h"
#include "Motor.h"
#include "Recetas.h"
#include "Config.h"

void inicializarTodoElHardware() {
    inicializarServos();
    inicializarSensores();
    inicializarMotor();
}
     
#include <Arduino.h>
#include "Servos.h"
#include "Sensores.h"
#include "Motor.h"
#include "Recetas.h"
#include "Config.h"

bool procesarPedidoBebida(int ingredientes[numeroIngredientes]) {
    
    // ============================================================
    // FASE 1: VALIDACIÓN DE TANQUES (Solo los necesarios)
    // ============================================================
    bool tanquesListos = true;
    String reporteFaltantes = "ERROR_FALTA:"; // Prefijo para enviar a Visual Studio 2026

    for (int i = 0; i < numeroIngredientes; i++) {
        // Solo validamos el tanque si la receta pide ese ingrediente (ingredientes[i] == 1)
        if (ingredientes[i] == 1) {
            int lecturaActual = leerDistancia(i + 1); // Sensor i corresponde a Servo i

            // Validación del tope (lectura debe ser mayor a ReservaMinimaTanque)
            // También protegemos el sistema si el sensor falla y devuelve -1
            if (lecturaActual <= ReservaMinimaTanque || lecturaActual == -1) {
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
    // Activamos todos los servos al mismo tiempo según el arreglo
    for (int i = 0; i < numeroIngredientes; i++) {
        if (ingredientes[i] == 1) {
            moverServo(i + 1, 180); // Abre válvula
        } else {
            moverServo(i + 1, 90);  // Mantiene cerrado
        }
    }

    // Esperamos el tiempo de servido con los servos en su posición
    delay(delayServido);

    // Al terminar el tiempo, cerramos ABSOLUTAMENTE TODOS los servos a 90°
    for (int i = 0; i < numeroIngredientes; i++) {
        moverServo(i + 1, 90);
    }
    
    // Pequeña pausa de seguridad antes de activar el mezclador
    delay(500); 

    return true; // Todo el proceso fue exitoso
}

